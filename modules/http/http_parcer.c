#include "http_parser.h"

int parse_http_request(char *request, HttpRequest *http_request) {
    if (sscanf(request, "%s %s", http_request->method, http_request->path) != 2) {
        return -1;
    }
    return 0;
}
