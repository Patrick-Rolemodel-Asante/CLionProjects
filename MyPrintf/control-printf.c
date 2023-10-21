#include "main.h"

/**
* validate - validates the format specifier
* @fmt: format specifier
* @charsPrinted: number of characters printed
* @substitutes: list of arguments
* Return: number of characters printed
*/


int validate(const char *fmt, int *charsPrinted, va_list substitutes)
{
	checkErrors(fmt);
	if (*fmt == 'l' && *(fmt + 1) == 'f')
		return (handleLfCase(charsPrinted, substitutes));
	else if (*fmt == '#')
		return (handleHashCase(&fmt, charsPrinted, substitutes));
	else if (*fmt == 'S')
		return (handleSCase(charsPrinted, substitutes));
	else
		return (handleSwitchCases(fmt, charsPrinted, substitutes));
}
