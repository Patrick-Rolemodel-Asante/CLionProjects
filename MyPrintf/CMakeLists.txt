cmake_minimum_required(VERSION 3.26)
project(MyPrintf C)

set(CMAKE_C_STANDARD 11)

add_executable(MyPrintf test/main.c
        main.h
        printf-errors.c
        _printf.c
        custom-conversion-specifiers.c
        other_helpers.c
        non-custom-conversion-specifiers.c
        control-printf.c
        other-custom-conversion-specifiers.c
        help_validate_function.c
        handlefloatNumbers.c

)
