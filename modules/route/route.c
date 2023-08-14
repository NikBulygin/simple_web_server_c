#include "route.h"

int map_path_to_file(const char *url_path, char *file_path) {
    const char *base_path = HTTP_REQUEST_BASE_PATH;
    char temp_path[HTTP_REQUEST_SIZE_OF_PATH];
    if (strcmp(url_path, "/") == 0) {
        snprintf(temp_path, sizeof(temp_path), "%s/index/index.html", base_path);
    } else {
        snprintf(temp_path, sizeof(temp_path), "%s%s", base_path, url_path);
    }

    if (strncmp(temp_path, base_path, strlen(base_path)) != 0) {
        return -1;
    }

    struct stat path_stat;
    stat(temp_path, &path_stat);
    if (S_ISDIR(path_stat.st_mode)) {
        strcat(temp_path, ".html");
    }

    FILE *file = fopen(temp_path, "r");
    if (file != NULL) {
        fclose(file);
        strcpy(file_path, temp_path);
        return 0;
    }

    return -1;
}



void route_api_request(HttpRequest *request, char *response)
{
    if (strcmp(request->method, "GET") == 0 && strcmp(request->path, "/api/function1") == 0) {
        //func1
        strcpy(response, "HTTP/1.1 404 NOT FOUND\nContent-Type: text/plain\n\nFunc1");
    } else if (strcmp(request->method, "POST") == 0 && strcmp(request->path, "/api/function2") == 0) {
        //func1
        strcpy(response, "HTTP/1.1 404 NOT FOUND\nContent-Type: text/plain\n\nFunc2");
    } else {
        strcpy(response, "HTTP/1.1 404 NOT FOUND\nContent-Type: text/plain\n\nNot Found");
    }
}
