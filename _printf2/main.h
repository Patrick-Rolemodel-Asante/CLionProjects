#ifndef _PRINTF2_MAIN_H
#define _PRINTF2_MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* function prototypes for task 0 */
int _printf(const char *format, ...);
int formatChar(va_list list);
int formatString(va_list list);

/* function prototypes for task 1 */
int formatInt(va_list list);

/* function prototypes for task 2 */
void _strcpy(char *res, char *rem);
char *changeToBaseN(unsigned int *num, int newBase);
unsigned int _strlen(char *rem);
int unsignedIntToBinary(unsigned int *num);

/* function prototypes for task 3 */
char *unsignedToSigned(unsigned int num);
char *unsignedIntToOct(unsigned int *num);
char *unsignedIntToHex(unsigned int *num);

/* function prototypes for task 5 */
int specialS(char *str);
char *convertToHex(int num);

#endif /*_PRINTF2_MAIN_H */
