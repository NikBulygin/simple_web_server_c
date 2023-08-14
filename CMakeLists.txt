cmake_minimum_required(VERSION 3.10)

project(WebServer C)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS_DEBUG "-g")
if(CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG)
endif()


add_executable(WebServer
  main.c
  config/socket_config.h
  config/logger_config.h
  config/http_request_config.h
  modules/socket/socket.c modules/socket/socket.h
  modules/route/route.c modules/route/route.h
  modules/http/http_parcer.c modules/http/http_parser.h
  modules/logger/logger.c modules/http/http_parser.h
)

# target_link_libraries(WebServer some_library)
