#ifndef HTTP_PARSER_H
#define HTTP_PARSER_H

#include <string.h>
#include <stdio.h>

#include "../../config/http_request_config.h"

typedef struct {
    /*
      HTTP declare methods: OPTIONS, GET, HEAD, POST, PUT, PATCH, DELETE, TRACE,
      CONNECT,
    */
    char method[HTTP_REQUEST_SIZE_OF_METHOD];
    char path[HTTP_REQUEST_SIZE_OF_PATH];
} HttpRequest;

int parse_http_request(char *request, HttpRequest *http_request);

#endif // HTTP_PARSER_H
