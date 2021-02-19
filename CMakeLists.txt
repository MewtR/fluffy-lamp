cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
SET(CMAKE_C_COMPILER /usr/bin/clang)
SET(CMAKE_CXX_COMPILER /usr/bin/clang++)
SET(CMAKE_CXX_FLAGS "-g -O0")

project(tcp_server)

add_executable(server server.cpp)
add_executable(client client.cpp)

set_target_properties(server client PROPERTIES CXX_STANDARD 20 RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/..")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_VERBOSE_MAKEFILE ON)
