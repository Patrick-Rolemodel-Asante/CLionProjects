//
// Created by rol on 10/7/23.
//


#include "main.h"

void stop(const char *str){
    perror(str);
    exit(EXIT_FAILURE);
}

void check_errors(const char *fmt){
    if (fmt == NULL)
        stop("Format string is NULL"); // Format string is NULL

    if ((*fmt == '%') && (*(fmt + 1) == '\0'))
        stop("No conversion character after % sign"); // No conversion specifier given after % sign
    if (*fmt == '\0') stop("Format string is empty"); // Format string is empty
}