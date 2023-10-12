cmake_minimum_required(VERSION 3.26)
project(MyPrintf C)

set(CMAKE_C_STANDARD 11)

add_executable(MyPrintf main.c
        main.h
        printf-errors.c
        my-printf.c
        functions_def.c
        other_helpers.c

)
