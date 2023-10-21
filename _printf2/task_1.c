#include "main.h"

unsigned char *strdup(unsigned char str[7]);

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

//int formatInt(va_list list)
//{
//
//	unsigned char intStr[32];
//	int intLen = 0, i = 0;
//	int arg = va_arg(list, int);
//	int temp = arg;
//	int len = 0;
//
//	if (arg < 0)
//	{
//		write(1, "-", 1);
//		len++;
//		arg = -arg;
//	}
//
//
//
//	if (temp == 0)
//		intStr[intLen++] = '0';
//	else
//	{
//		while (temp > 0)
//		{
//			intStr[intLen++] = '0' + (temp % 10);
//			temp /= 10;
//		}
//	}
//
//	for (i = intLen - 1; i >= 0; i--)
//	{
//		write(1, &intStr[i], 1);
//		len++;
//	}
//
//	return (len);
//}





// Function to print a character array
void printString(const unsigned char *str, int *digitsPrinted) {
    int len = 0;
    while (str[len] != '\0') {
	write(1, &str[len], 1);
	len++;
	(*digitsPrinted)++;
    }
}

// Function to convert an integer part of a floating-point number to a string
unsigned char* integerPartToString(int intPart) {
    unsigned char *intStr = malloc(32 * sizeof(unsigned char));

    if (intStr == NULL) {
	stop("Error allocating memory");
    }

    int i = 0;

    do {
	intStr[i++] = '0' + (intPart % 10);
	intPart /= 10;
    } while (intPart != 0);
    intStr[i] = '\0';

    // Reverse the integer part string
    int len = i;
    for (int j = 0; j < len / 2; j++) {
	unsigned char temp = intStr[j];
	intStr[j] = intStr[len - j - 1];
	intStr[len - j - 1] = temp;
    }

    return intStr;
}

// Function to convert the fractional part of a floating-point number to a string
unsigned char* fractionalPartToString(double fracPart) {
    unsigned char fracStr[7];

    for (int i = 0; i < 6; i++) {
	fracPart *= 10;
	fracStr[i] = '0' + ((int) fracPart % 10);
	fracPart -= (int) fracPart;
    }
    fracStr[6] = '\0';

    return strdup(fracStr);
}

unsigned char *strdup(unsigned char str[7])
{
    unsigned char *newStr = malloc(7 * sizeof(unsigned char));

    if (newStr == NULL) {
	stop("Error allocating memory");
    }

    for (int i = 0; i < 7; i++) {
	newStr[i] = str[i];
    }

    return newStr;
}

int formatFloatingNumber(va_list args) {
    double arg = va_arg(args, double);
    int digitsPrinted = 0;

    if (arg < 0) {
	write(1, "-", 1);
	digitsPrinted++;
	arg = -arg;
    }

    int intPart = (int)arg;
    unsigned char *intStr = integerPartToString(intPart);

    // Print the integer part
    printString(intStr, &digitsPrinted);

    write(1, ".", 1);
    digitsPrinted++;

    double fracPart = arg - intPart;
    unsigned char *fracStr = fractionalPartToString(fracPart);

    // Print the fractional part
    printString(fracStr, &digitsPrinted);

    free(intStr);
    free(fracStr);

    return digitsPrinted;
}
