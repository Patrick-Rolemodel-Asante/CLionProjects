#include "main.h"


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


/**
* formatChar - prints a character
* @args: list of arguments
* Return: number of characters printed
*/

int formatChar(va_list args)
{
	char arg = va_arg(args, int);

	write(1, &arg, 1);
	return (1);
}

/**
* formatString - prints a string
* @args: list of arguments
* Return: number of characters printed
*/

int formatString(va_list args)
{
	char *arg = va_arg(args, char *);
	int len = 0;

	if (arg == NULL)
		arg = "(null)";
	while (*arg)
	{
		write(1, arg, 1);
		arg++;
		len++;
	}

	return (len);
}
