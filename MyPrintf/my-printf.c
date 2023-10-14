#include "main.h"

// the return value is the number of characters printed
// optimize the code because I am not getting the correct number of characters printed

int _printf(const char *fmt, ...) {
    check_errors(fmt);

    int chars_printed = 0;
    va_list substitutes;
    va_start(substitutes, fmt);

    while (*fmt){
        if (*fmt != '%') {
            write(1, fmt, 1);
            chars_printed++;
        } else {
            fmt++;
            validate(fmt,&chars_printed,substitutes);
        }
        if (*fmt == '#' || *fmt == 'l') ++fmt;
        fmt++;
    }
    va_end(substitutes);
    return (chars_printed);
}

