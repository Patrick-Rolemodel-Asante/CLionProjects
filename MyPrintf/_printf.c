#include "main.h"

/**
* _printf - prints a formatted string
* * @fmt: format specifier
* @...: list of arguments
* Return: number of characters printed
*/

int _printf(const char *fmt, ...)
{
	int charsPrinted = 0;
	va_list substitutes;

	checkErrors(fmt);

	va_start(substitutes, fmt);

	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt++;
			validate(fmt, &charsPrinted, substitutes);
			if (*fmt == 'l')
			fmt += 2;
		}
		else
		{
			write(1, fmt, 1);
			charsPrinted++;
		}
	fmt++;
	}

	va_end(substitutes);

	return (charsPrinted);
}
