#ifndef MYPRINTF_MAIN_H
#define MYPRINTF_MAIN_H

#include <stdarg.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
void checkErrors(const char *fmt);
void stop(const char *str);

int formatFloatingNumber(va_list args);
int doubleCase(int *charsPrinted, va_list substitutes);
char *changeToBaseN(unsigned long int num, int newBase);
int myHex(const char *fmt, const unsigned long *num);
int myOct(const unsigned long *num);
int writeMe(const long *num, int base, char letter);
void lowerCase(char *newNum);
int address(const long *num);
int myBin(const unsigned long *num);
int stringReverse(const char *str);
void rot13(char *s);
int handleCustomS(va_list substitutes);


char *convertToHex(int num);
int formatPercent();
int formatString(va_list args);
int formatChar(va_list args);
int formatInt(va_list args);
int formatUnsigned(va_list args);
int handleSwitchCases(const char *fmt, int *charsPrinted, va_list
substitutes);
int handleSCase(int *charsPrinted, va_list substitutes);
int handleHashCase(const char **fmt, int *charsPrinted, va_list substitutes);
int moreSwitchCases(va_list substitutes, const char *fmt, int *charsPrinted);


int validation(const char *fmt, int *charsPrinted, va_list substitutes);
int _printf(const char *format, ...);
#endif /* MYPRINTF_MAIN_H */
