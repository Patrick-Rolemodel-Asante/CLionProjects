#ifndef MYPRINTF_MAIN_H
#define MYPRINTF_MAIN_H

#include <stdarg.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>


/**
 * enum format - Enumeration for different format types *
 * @INT: Represents an integer format type
 * @CHAR: Represents a character format type
 * @STRING: Represents a string format type
 * @PERCENT: Represents a percentage format type
 * @UNSIGNED: Represents an unsigned integer format type
 *
 * Description: This enumeration is used to represent different
 * format types in the program. Each member corresponds to a
 * specific format type.
 */
typedef enum format
{
INT,
CHAR,
STRING,
PERCENT,
UNSIGNED,
} fmt;

int (*printFunction[])(va_list);

int _printf(const char *fmt, ...);

void stop(const char *str);
void check_errors(const char *fmt);




char *changeToBaseN(unsigned long int num, int new_base);
int myHex(char *fmt, unsigned long *num);
int myOct(unsigned long *num);
int writeMe(unsigned long *num, int base, char letter);
void lowerCase(char *new_num);
int _printf(const char *format, ...);
int handleAddress(char *fmt, unsigned long *num);
int myBin(unsigned long *num);
int string_reverse(char *str);
void rot13(char *s);
int handleCustomS(va_list substitutes);
char *convertToHex(int num);


int format_PERCENT(va_list empty);
int format_STRING(va_list args);
int format_CHAR(va_list args);
int format_INT(va_list args);
int format_UNSIGNED(va_list args);
int validate(char *fmt, int *chars_printed, va_list substitutes);
int handleLfCase(char **fmt, int *chars_printed, va_list substitutes);
int handleSwitchCases(char *fmt, int *chars_printed, va_list
substitutes);
int handleSCase(char **fmt, int *chars_printed, va_list
substitutes);
int handleHashCase(char **fmt, int *chars_printed, va_list
substitutes);


int format_floating_number(va_list args, int flag);
#endif /* MYPRINTF_MAIN_H */
