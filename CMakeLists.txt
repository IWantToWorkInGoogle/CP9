cmake_minimum_required(VERSION 3.22)
project(CP9 C)

set(CMAKE_C_STANDARD 99)

add_executable(CP9 main.c map.c map.h String.c String.h reading.c reading.h)
