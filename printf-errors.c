#include "main.h"

/**
 * stop - prints an error message and exits the program
 * @str: the error message to print
 *
 * Return: nothing
 */
void stop(const char *str)
{
perror(str);
exit(EXIT_FAILURE);
}

/**
 * check_errors - checks for errors in the format string
 * @fmt: the format string
 *
 * Return: nothing
 */
void check_errors(const char *fmt)
{
if (fmt == NULL)
stop("format string is NULL");
if (strlen(fmt) == 0)
stop("format string is empty");
if (fmt[0] == '%' && fmt[1] == '\0')
stop("invalid format string");
}
