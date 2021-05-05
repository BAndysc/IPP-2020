cmake_minimum_required(VERSION 3.13)
project(IPPShellTest C)

set(CMAKE_C_FLAGS "-fsanitize=address -g")

set(CMAKE_C_STANDARD 11)

add_executable(IPPShellTest main.c parser.c input.c input.h string.c string.h builtins.c builtins.h)