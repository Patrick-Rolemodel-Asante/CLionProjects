#include "main.h"


unsigned char *_strdup(unsigned char str[7]);

/**
 * printString - Prints a string to stdout.
 * @str: The string to be printed.
 * @digitsPrinted: The number of digits printed so far.
 * Return: void
 */

void printString(const unsigned char *str, int *digitsPrinted)
{
	int len = 0;

	while (str[len] != '\0')
	{
		write(1, &str[len], 1);
		len++;
		(*digitsPrinted)++;
	}
}

/**
 * integerPartToString - Converts the integer part of a floating-point
 * number to a string.
 * @intPart: The integer part of the floating-point number.
 * Return: The integer part as a string.
 */

unsigned char *integerPartToString(int intPart)
{
	unsigned char *intStr = malloc(32 * sizeof(unsigned char));

	if (intStr == NULL)
		stop("Error allocating memory");

	int i = 0;

	do {
		intStr[i++] = '0' + (intPart % 10);
		intPart /= 10;
	} while (intPart != 0);

	intStr[i] = '\0';

	/* Reverse the string */
	int len = i;

	for (int j = 0; j < len / 2; j++)
	{
		unsigned char temp = intStr[j];

		intStr[j] = intStr[len - j - 1];
		intStr[len - j - 1] = temp;
	}

	return (intStr);
}

/**
 * fractionalPartToString - Converts the fractional part of a
 * floating-point number to a string.
 * @fracPart: The fractional part of the floating-point number.
 * Return: The fractional part as a string.
 */


unsigned char *fractionalPartToString(double fracPart)
{
	unsigned char fracStr[7];

	for (int i = 0; i < 6; i++)
	{
		fracPart *= 10;
		int digit = (int)(fracPart + 0.5); /* Round to nearest integer */

		fracStr[i] = '0' + (digit % 10);
		fracPart -= digit;
	}
	fracStr[6] = '\0';

	return (_strdup(fracStr)); /* strdup() allocates memory for the string */
}

unsigned char *_strdup(unsigned char str[7])
{
	unsigned char *newStr = malloc(7 * sizeof(unsigned char));

	if (newStr == NULL)
		stop("Error allocating memory");

	for (int i = 0; i < 7; i++)
		newStr[i] = str[i];

	return (newStr);
}


/**
* formatFloatingNumber - prints a floating number
* @args: list of argument
* Return: number of characters printed
*/

int formatFloatingNumber(va_list args)
{
	double arg = va_arg(args, double);
	int digitsPrinted = 0;

	if (arg < 0)
	{
		write(1, "-", 1);
		digitsPrinted++;
		arg = -arg;
	}

	int intPart = (int)arg;
	unsigned char *intStr = integerPartToString(intPart);

	/* Print the integer part */
	printString(intStr, &digitsPrinted);

	write(1, ".", 1);
	digitsPrinted++;

	double fracPart = arg - intPart;
	unsigned char *fracStr = fractionalPartToString(fracPart);

	/* Print the fractional part */
	printString(fracStr, &digitsPrinted);

	free(intStr);
	free(fracStr);

	return (digitsPrinted);
}
