#ifndef MYPRINTF_MAIN_H
#define MYPRINTF_MAIN_H

#include <stdarg.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Include for the write function


typedef enum {
    INT,
    CHAR,
    STRING,
    FLOAT,
    DOUBLE,
    PERCENT,
} fmt;



int _myprintf(const char *format, ...);

void stop(const char *str);
void check_errors(const char *fmt);

int format_PERCENT(va_list empty);
int format_FLOAT(va_list args);
int format_STRING(va_list args);
int format_CHAR(va_list args);
int format_INT(va_list args);
int format_DOUBLE(va_list args);

int validate(const char *fmt, int *chars_printed, va_list substitutes);

char  *change_to_baseN(unsigned long int num, int new_base);
int my_hex(const char *fmt, unsigned long int *num);
int my_oct(const char *fmt, unsigned long *num);

#endif // MYPRINTF_MAIN_H



