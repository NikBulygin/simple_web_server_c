#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "modules/socket/socket.h"
#include "config/socket_config.h"

void *thread_connection_socket(void *client_socket_ptr) {
    int client_socket = *(int *)client_socket_ptr;
    free(client_socket_ptr);

    handle_connection_socket(client_socket);
    
    close(client_socket);
    pthread_exit(NULL);
}

int main() {
    int server_fd = create_socket(8085);

    while (1) {
        int *client_socket_ptr = malloc(sizeof(int));
        *client_socket_ptr = accept(server_fd, NULL, NULL);

        pthread_t client_thread;
        int thread_status = pthread_create(&client_thread, NULL, thread_connection_socket, client_socket_ptr);
        if (thread_status != 0) {
            fprintf(stderr, "Ошибка при создании потока: %d\n", thread_status);
            return 1;
        }

        pthread_detach(client_thread);
    }

    close(server_fd);
    return 0;
}
