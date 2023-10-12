//
// Created by rol on 10/12/23.
//
#include "variadic_functions.h"
//
// Created by rol on 10/12/23.

//
#include "variadic_functions.h"

//Write a function that prints anything.
void print_all(const char * const format, ...)
{
    va_list args;
    int i = 0, j = 0;
    char *str;
    const char *sep = "";

    va_start(args, format);
    while (format && format[i])
    {
        j = 1;
        switch (format[i])
        {
            case 'c':
                printf("%s%c", sep, va_arg(args, int));
                break;
            case 'i':
                printf("%s%d", sep, va_arg(args, int));
                break;
            case 'f':
                printf("%s%f", sep, va_arg(args, double));
                break;
            case 's':
                str = va_arg(args, char *);
                if (str == NULL)
                    str = "(nil)";
                printf("%s%s", sep, str);
                break;
            default:
                j = 0;
                break;
        }
        if (j)
            sep = ", ";
        i++;
    }
    printf("\n");
    va_end(args);
}