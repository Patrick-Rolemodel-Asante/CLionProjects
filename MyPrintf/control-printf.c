#include "main.h"

/**
* validate - validates the format specifier
* @fmt: format specifier
* @chars_printed: number of characters printed
* @substitutes: list of arguments
* Return: number of characters printed
*/


int validate(char *fmt, int *chars_printed, va_list substitutes)
{
check_errors(fmt);
if (*fmt == 'l' && *(fmt + 1) == 'f')
return (handleLfCase(&fmt, chars_printed, substitutes));
else if (*fmt == '#')
return (handleHashCase(&fmt, chars_printed, substitutes));
else if (*fmt == 'S')
return (handleSCase(&fmt, chars_printed, substitutes));
else
return (handleSwitchCases(fmt, chars_printed, substitutes));
}
