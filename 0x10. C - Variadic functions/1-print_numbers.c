//
// Created by rol on 10/12/23.
//
//
// Created by rol on 10/12/23.
//Write a function that prints numbers, followed by a new line.
//
#include "variadic_functions.h"
void print_numbers(const char *separator, const unsigned int n, ...)
{
    va_list args;
    unsigned int i;

    va_start(args, n);

    for (i = 0; i < n; i++)
    {
        printf("%d", va_arg(args, int));
        if (separator != NULL && i != n - 1)
            printf("%s", separator);
    }
    printf("\n");
    va_end(args);
}