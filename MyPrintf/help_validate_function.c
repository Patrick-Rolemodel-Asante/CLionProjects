#include "main.h"

/**
 * doubleCase - handles the lf case
 * @charsPrinted: number of characters printed
 * @substitutes: list of arguments
 * Return: number of characters printed
 */

int doubleCase(int *charsPrinted, va_list substitutes)
{
	*charsPrinted = formatFloatingNumber(substitutes);
	return (*charsPrinted);
}


/**
 * handleSwitchCases - handles the switch cases
 * @fmt: format specifier
 * @charsPrinted: number of characters printed
 * @substitutes: list of arguments
 * Return: number of characters printed
 */

int handleSwitchCases(const char *fmt, int *charsPrinted, va_list substitutes)
{
	switch (*fmt)
	{
	case '%':
		*charsPrinted += formatPercent();
		break;
	case 'c':
		*charsPrinted = formatChar(substitutes);
		break;
	case 'b':
	{
		unsigned long int num = va_arg(substitutes, unsigned long int);
		*charsPrinted = myBin(&num);
		break;
	}
	case 's':
		*charsPrinted = formatString(substitutes);
		break;
	case 'u':
		*charsPrinted = formatUnsigned(substitutes);
		break;
	case 'd':
	case 'i':
		*charsPrinted = formatInt(substitutes);
		break;
	case 'f':
	{
		*charsPrinted += formatFloatingNumber(substitutes);
		break;
	}
	default:
		*charsPrinted = moreSwitchCases(substitutes, fmt, charsPrinted);
	}
	return (*charsPrinted);
}

/**
 * handleSCase - handles the S case
 * @charsPrinted: number of characters printed
 * @substitutes: list of arguments
 * Return: number of characters printed
 */

int handleSCase(int *charsPrinted, va_list substitutes)
{
	return (*charsPrinted = handleCustomS(substitutes));
}

/**
 * handleHashCase - handles the # case
 * @fmt: format specifier
 * @charsPrinted: number of characters printed
 * @substitutes: list of arguments
 * Return: number of characters printed
 */

int handleHashCase(const char **fmt, int *charsPrinted, va_list substitutes)
{
	if (*(*fmt + 1) == 'x' || *(*fmt + 1) == 'X')
	{
		unsigned long int num = va_arg(substitutes, unsigned long int);
		*charsPrinted = myHex(*fmt, &num);
	}
	else if (**fmt == 'o')
	{
		unsigned long int num = va_arg(substitutes, unsigned long int);
		*charsPrinted = myOct(&num);
	}
	else
		stop("Invalid format specifier!");

	return (*charsPrinted);
}

/**
 * moreSwitchCases - handles the rest of the format strings
 * @substitutes: va_list to be inserted
 * @fmt: format string
 * @charsPrinted: number of characters printed
 * Return: the number of characters printed
 */
int moreSwitchCases(va_list substitutes, const char *fmt, int *charsPrinted)
{
	long int num;

	switch (*fmt)
	{
	case 'X':
	case 'x': {
	if (*fmt == 'x')
	{
		num = va_arg(substitutes, long int);
		*charsPrinted += writeMe(&num, 16, 'x');
		break;
	}
		num = va_arg(substitutes,  long int);
		*charsPrinted = writeMe(&num, 16, 'X');
		break;
	}
	case 'o':
	{
		num = va_arg(substitutes, long int);
		*charsPrinted = writeMe(&num, 8, 'o');
		break;
	}
	case 'p':
	{
		num = va_arg(substitutes, long int);
		*charsPrinted = address(&num);
		break;
	}
	default:
	{
		write(1, "%", 1);
		write(1, fmt, 1);
		*charsPrinted += 2;
	}
	}
	return (*charsPrinted);
}
