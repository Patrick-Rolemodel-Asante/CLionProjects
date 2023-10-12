cmake_minimum_required(VERSION 3.26)
project(MyC C)

set(CMAKE_C_STANDARD 11)

add_executable(MyC main.c
        nestedRecursion.cpp
        nestedRecursion.h)
