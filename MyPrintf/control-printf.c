#include "main.h"

/**
 * validate - validates the format specifier
 * @fmt: format specifier
 * @chars_printed: number of characters printed
 * @substitutes: list of arguments
 * Return: number of characters printed
 */

int validate(const char *fmt, int *chars_printed, va_list substitutes)
{
    if (*fmt == 'l' && *(fmt + 1) == 'f')
    {
	*chars_printed = (*printFunction[DOUBLE])(substitutes);
	fmt += 2;
    }
    else
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
	    {
		unsigned long int num = va_arg(substitutes, unsigned long int);
		*chars_printed = myBin(&num);
		break;
	    }
	    case 's':
		*chars_printed = (*printFunction[STRING])(substitutes);
		break;
	    case 'u':
		*chars_printed = (*printFunction[UNSIGNED])(substitutes);
		break;
	    case 'd':
	    case 'i':
		*chars_printed = (*printFunction[INT])(substitutes);
		break;
	    case 'f':
		*chars_printed += (*printFunction[FLOAT])(substitutes);
		fmt++;
		break;
	    case 'X':
	    {
		unsigned long int num = va_arg(substitutes, unsigned long int);
		*chars_printed = writeMe(&num, 16, 'X');
		break;
	    }
	    case 'x':
	    {
		unsigned long int num = va_arg(substitutes, unsigned long int);
		*chars_printed += writeMe(&num, 16, 'x');
		break;
	    }
	    case 'o':
	    {
		unsigned long int num = va_arg(substitutes, unsigned long int);
		*chars_printed = writeMe(&num, 8, 'o');
		break;
	    }
	    case 'p': {
		unsigned long int num = va_arg(substitutes, unsigned long int);
		*chars_printed = handleAddress(fmt, &num);
		break;
	    }
	    case '#':
		++fmt;
		if (*fmt == 'x' || *fmt == 'X')
		{
		    unsigned long int num = va_arg(substitutes, unsigned long int);
		    *chars_printed = myHex(fmt, &num);
		}
		else if (*fmt == 'o')
		{
		    unsigned long int num = va_arg(substitutes, unsigned long int);
		    *chars_printed = myOct(&num);
		}
	    default:
		write(1, "%", 1);
		write(1, &(*fmt), 1);
		*chars_printed += 2;
	}
    }
    return (*chars_printed);
}


int validate1(const char *fmt, int *chars_printed, va_list substitutes)
{
    if (*fmt == 'l' && *(fmt + 1) == 'f')
	return (handleLfCase(&fmt, chars_printed, substitutes));
    else if (*fmt == '#')
	return (handleHashCase(&fmt, chars_printed, substitutes));
    else if (*fmt == 'S')
	return (handleSCase(&fmt, chars_printed, substitutes));
    else
	return (handleSwitchCases(&fmt, chars_printed, substitutes));
}
