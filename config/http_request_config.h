#ifndef WEB_SERVER_HTTP_REQUEST_CONFIG_H
#define WEB_SERVER_HTTP_REQUEST_CONFIG_H

#include "socket_config.h"

/*
  HTTP DECLARE NEXT:
      OPTIONS
      GET 
      HEAD
      POST
      PUT
      PATCH
      DELETE
      TRACE
      CONNECT

      max length is 7 character
*/
#define HTTP_REQUEST_SIZE_OF_METHOD 8
#define HTTP_REQUEST_SIZE_OF_PATH MAX_LENGTH_OF_URL_STRING -  HTTP_REQUEST_SIZE_OF_METHOD
#define HTTP_REQUEST_BASE_PATH "/home/nik/Documents/C-simple_web_server/web_pages"
#endif // WEB_SERVER_HTTP_REQUEST_CONFIG_H

