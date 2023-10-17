#ifndef MYPRINTF_MAIN_H
#define MYPRINTF_MAIN_H

#include <stdarg.h> // Include for the va_list type
#include <errno.h> // Include for the errno variable
#include <stdio.h> // Include for the write function
#include <stdlib.h> // Include for the malloc function
#include <string.h> // Include for the strlen function
#include <unistd.h> // Include for the write function
#include <limits.h> // Include for the INT_MAX and INT_MIN macros



typedef enum {
    INT,
    CHAR,
    STRING,
    FLOAT,
    DOUBLE,
    PERCENT,
    UNSIGNED,
} fmt;

int (*printFunction[])(va_list);

int _printf(const char *fmt, ...);

void stop(const char *str);
void check_errors(const char *fmt);



int validate(const char *fmt, int *chars_printed, va_list substitutes);

char *change_to_baseN(unsigned long int num, int new_base);
int my_hex(const char *fmt, unsigned long *num);
int my_oct(const unsigned long *num);
int write_me(const unsigned long *num, int base, char letter);
void lower_case(char * new_num);
int _printf(const char *format, ...);
int handle_address(const char *fmt, unsigned long *num);
int my_bin(const unsigned long *num);
int string_reverse(char *str);
void rot13(char *s);
int handle_custom_s(va_list substitutes);
char *convert_to_hex(int num);


int format_PERCENT(va_list empty);
int format_FLOAT(va_list args);
int format_STRING(va_list args);
int format_CHAR(va_list args);
int format_INT(va_list args);
int format_DOUBLE(va_list args);
int format_UNSIGNED(va_list args);
void handle_lf_case(const char **fmt, int *chars_printed, va_list substitutes);
void handle_switch_cases(const char **fmt, int *chars_printed, va_list
substitutes);
void handle_other_cases(const char **fmt, int *chars_printed, va_list
substitutes);
void handle_hash_case(const char **fmt, int *chars_printed, va_list
substitutes);

#endif // MYPRINTF_MAIN_H
