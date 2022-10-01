cmake_minimum_required(VERSION 3.23)
project(CSocketServer C)

set(CMAKE_C_STANDARD 99)

add_executable(CSocketServer main.c utils/sock.c utils/sock.h)
