cmake_minimum_required(VERSION 3.17)
project(TriImage C)

set(CMAKE_C_STANDARD 99)

add_executable(TriImage main.c libbmp.c functions.h Compare.h Compare.c Sort.h Sort.c)