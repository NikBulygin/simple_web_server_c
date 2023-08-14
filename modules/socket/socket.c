#include "socket.h"

int create_socket(int port)
{
    logger("start create a socket");
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 10);
    
    logger("socket was created");
    return server_fd;
}

void handle_api_request(HttpRequest *request, char *response) {
    logger("get new api request");
    memset(response, 0, 8192);
    logger(request->method);
    logger(request->path);
    logger(response);
    char file_path[HTTP_REQUEST_SIZE_OF_PATH];
    if (map_path_to_file(request->path, file_path) == 0) {
        FILE *file = fopen(file_path, "r");
        if (file != NULL) {
            const char *content_type = "text/html"; // По умолчанию
            if (strstr(file_path, ".css") != NULL) {
                content_type = "text/css";
            } else if (strstr(file_path, ".js") != NULL) {
                content_type = "application/javascript";
            }
            snprintf(response, 8192, "HTTP/1.1 200 OK\nContent-Type: %s\n\n", content_type);
            fread(response + strlen(response), 1, 8192 - strlen(response) - 1, file);
            fclose(file);
        } else {
            strcpy(response, "HTTP/1.1 404 Not Found\nContent-Type: text/html\n\nFile not found");
        }
    } else {
        route_api_request(request, response);
    }
}



void handle_connection_socket(int client_socket)
{
    //max length of URL string is 8 kb
    char buffer[MAX_LENGTH_OF_URL_STRING] = {0};
    read(client_socket, buffer, MAX_LENGTH_OF_URL_STRING);
    char response[MAX_LENGTH_OF_URL_STRING];
     
     HttpRequest request;
    if (parse_http_request(buffer, &request) < 0) {
        //func1
        strcpy(response,
               "HTTP/1.1 400 BAD REQUEST\nContent-Type: text/plain\n\nBad Request");
    } else {
       
        handle_api_request(&request, response);
    }

    send(client_socket, response, strlen(response), 0);
    close(client_socket);
}
