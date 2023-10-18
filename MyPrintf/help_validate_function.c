#include "main.h"

/**
 * handleLfCase - handles the lf case
 * @fmt: format specifier
 * @chars_printed: number of characters printed
 * @substitutes: list of arguments
 * Return: number of characters printed
 */

int handleLfCase(char **fmt, int *chars_printed, va_list substitutes)
{
*chars_printed = format_floating_number(substitutes, 1);
return (*chars_printed);
}

/**
 * handleSwitchCases - handles the switch cases
 * @fmt: format specifier
 * @chars_printed: number of characters printed
 * @substitutes: list of arguments
 * Return: number of characters printed
 */


int handleCase(char *format, int (*printFunc[])(va_list), va_list substitutes)
{
    unsigned long int num = va_arg(substitutes, unsigned long int);
    return printFunc(&num);
}

int handleSwitchCases(char *fmt, int *chars_printed, va_list substitutes)
{
    switch (*fmt)
    {
	case '%':
	    *chars_printed += (*printFunction[PERCENT])(substitutes);
	    break;
	case '\n':
	    *chars_printed = (*printFunction[PERCENT])(substitutes);
	    break;
	case 'c':
	    *chars_printed = (*printFunction[CHAR])(substitutes);
	    break;
	case 'b':
	    *chars_printed = handleCase(*fmt, myBin, substitutes);
	    break;
	case 's':
	    *chars_printed = (*printFunction[STRING])(substitutes);
	    break;
	case 'u':
	    *chars_printed = format_UNSIGNED(substitutes);
	    break;
	case 'd':
	case 'i':
	    *chars_printed = (*printFunction[INT])(substitutes);
	    break;
	case 'f':
	    *chars_printed += format_floating_number(substitutes, 0);
	    break;
	case 'X':
	case 'x':
	    if (*fmt == 'x')
		*chars_printed += handleCase(fmt, writeMe, substitutes);
	    else
		*chars_printed = handleCase(fmt, writeMe, substitutes);
	    break;
	case 'o':
	    *chars_printed = handleCase(fmt, writeMe, substitutes);
	    break;
	case 'p':
	    *chars_printed = handleCase(fmt, handleAddress(), substitutes);
	    break;
	default:
	    write(1, "%", 1);
	    write(1, fmt, 1);
	    *chars_printed += 2;
    }
    return (*chars_printed);
}


/**
 * handleSCase - handles the S case
 * @fmt: format specifier
 * @chars_printed: number of characters printed
 * @substitutes: list of arguments
 * Return: number of characters printed
 */

int handleSCase(char **fmt, int *chars_printed, va_list substitutes)
{
return (*chars_printed = handleCustomS(substitutes));
}

/**
 * handleHashCase - handles the # case
 * @fmt: format specifier
 * @chars_printed: number of characters printed
 * @substitutes: list of arguments
 * Return: number of characters printed
 */

int handleHashCase(char **fmt, int *chars_printed, va_list substitutes)
{
if (*(*fmt + 1) == 'x' || *(*fmt + 1) == 'X')
{
unsigned long int num = va_arg(substitutes, unsigned long int);
*chars_printed = myHex(*fmt, &num);
}
else if (**fmt == 'o')
{
unsigned long int num = va_arg(substitutes, unsigned long int);
*chars_printed = myOct(&num);
}
else
stop("Invalid format specifier!");

return (*chars_printed);
}
