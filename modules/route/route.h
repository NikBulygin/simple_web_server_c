#ifndef WEB_SERVER_ROUTE_H
#define WEB_SERVER_ROUTE_H

#include <string.h>
#include <stdio.h>
#include <sys/stat.h>

#include "../http/http_parser.h"
#include "../../config/http_request_config.h"

int map_path_to_file(const char *url_path, char *file_path);
void route_api_request(HttpRequest *request, char *response);
#endif // WEB_SERVER_ROUTE_H
