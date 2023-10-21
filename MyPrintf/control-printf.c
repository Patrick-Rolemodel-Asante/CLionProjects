#include "main.h"

/**
* validation - validates the format specifier
* @fmt: format specifier
* @charsPrinted: number of characters printed
* @substitutes: list of arguments
* Return: number of characters printed
*/



int validation(const char *fmt, int *charsPrinted, va_list substitutes)
{
	if (*fmt == 'l' && *(fmt + 1) == 'f')
		return (doubleCase(charsPrinted, substitutes));
	else if (*fmt == '#')
		return (handleHashCase(&fmt, charsPrinted, substitutes));
	else if (*fmt == 'S')
		return (handleSCase(charsPrinted, substitutes));
	else
		return (handleSwitchCases(fmt, charsPrinted, substitutes));
}
