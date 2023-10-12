#include "main.h"

int _printf(const char *fmt, ...){
    unsigned long chars_printed = 0;
    char con_specifiers[] = {'c', 's', '%'};

    if (fmt == NULL || ((*fmt == '%') && (*(fmt + 1)) == '\0'))
        return (-1);

    va_list substitutes;
    va_start(substitutes, fmt);

    while (*fmt){
        if (*fmt != '%') {
            write(1, fmt, 1);
            chars_printed++;
        } else {
            fmt++;
            if (*fmt == '%' || *fmt == '\n'){
                write(1, fmt,1);
                chars_printed++;
            }else if (*fmt == 'c'){
                char c = va_arg(substitutes, int);
                write(1, &c, 1);
                chars_printed++;
            } else if (*fmt == 's'){
                char *str = va_arg(substitutes, char *);
                write(1,str,strlen(str));
                chars_printed +=  strlen(str);
            } else if (*fmt == 'd'){
                char temp = va_arg(substitutes, int );
                write(1, &temp, sizeof(temp));
                chars_printed++;
            }

        }
        fmt++;
    }


    va_end(substitutes);
    return (chars_printed);

}