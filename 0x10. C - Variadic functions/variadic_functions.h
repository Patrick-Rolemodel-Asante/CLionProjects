//
// Created by rol on 10/12/23.
//

#ifndef UNTITLED1_VARIADIC_FUNCTIONS_H
#define UNTITLED1_VARIADIC_FUNCTIONS_H

#include <stdarg.h>
#include <stdio.h>
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

#endif //UNTITLED1_VARIADIC_FUNCTIONS_H
