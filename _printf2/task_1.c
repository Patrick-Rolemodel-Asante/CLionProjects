#include "../main.h"

/**
 * _printf - prints a formatted string
 * @format: string to be printed
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int charsPrinted = 0;
	int i = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
				charsPrinted++;
			} else if (format[i] == 'd' || format[i] == 'i')
			{
				charsPrinted += formatInt(args);
			} else
			{
				write(1, "%", 1);
				write(1, &format[i], 1);
				charsPrinted += 2;
			}
		} else
		{
			write(1, &format[i], 1);
			charsPrinted++;
		}
		i++;
	}
	va_end(args);
	return (charsPrinted);
}

/**
 * formatInt - prints an integer
 * @list: list of arguments
 * Return: number of characters printed
 */

int formatInt(va_list list)
{

	unsigned char intStr[32];
	int intLen = 0, i = 0;
	int arg = va_arg(list, int);
	int temp = arg;
	int len = 0;

	if (arg < 0)
	{
		write(1, "-", 1);
		len++;
		arg = -arg;
	}



	if (temp == 0)
		intStr[intLen++] = '0';
	else
	{
		while (temp > 0)
		{
			intStr[intLen++] = '0' + (temp % 10);
			temp /= 10;
		}
	}

	for (i = intLen - 1; i >= 0; i--)
	{
		write(1, &intStr[i], 1);
		len++;
	}

	return (len);
}
