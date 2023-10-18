#include "main.h"

int handleLfCase(char **fmt, int *chars_printed, va_list substitutes)
{
    *chars_printed = (*printFunction[DOUBLE])(substitutes);
    return (*chars_printed);
}


int handleSwitchCases(char *fmt, int *chars_printed, va_list substitutes) {
    switch (*fmt) {
	case '%':
	    *chars_printed += (*printFunction[PERCENT])(substitutes);
	    break;
	case '\n':
	    *chars_printed = (*printFunction[PERCENT])(substitutes);
	    break;
	case 'c':
	    *chars_printed = (*printFunction[CHAR])(substitutes);
	    break;
	case 'b': {
	    unsigned long int num = va_arg(substitutes, unsigned long int);
	    *chars_printed = myBin(&num);  // Fixed function name.
	    break;
	}
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
	{
	    *chars_printed += (*printFunction[FLOAT])(substitutes);
	    (*fmt)++;
	    break;
	}
	case 'X':
	case 'x':
	{
	    if (*fmt == 'x') {
		unsigned long int num = va_arg(substitutes, unsigned long int);
		*chars_printed += writeMe(&num, 16, 'x');
		break;
	    }
	    unsigned long int num = va_arg(substitutes, unsigned long int);
	    *chars_printed = writeMe(&num, 16, 'X');
	    break;
	}
	case 'o':
	{
	    unsigned long int num = va_arg(substitutes, unsigned long int);
	    *chars_printed = writeMe(&num, 8, 'o');
	    break;
	}
	default:
	{
	    write(1, "%", 1);
	    write(1, fmt, 1);
	    *chars_printed += 2;
	}
    }
    return (*chars_printed);
}


int handleSCase(char **fmt, int *chars_printed, va_list substitutes) {
    *chars_printed = handleCustomS(substitutes);  // Fixed function name.
    return (*chars_printed);
}


int handleHashCase(char **fmt, int *chars_printed, va_list substitutes) {
    if (*(*fmt + 1) == 'x' || *(*fmt + 1) == 'X') {
	unsigned long int num = va_arg(substitutes, unsigned long int);
	*chars_printed = myHex(*fmt, &num);  // Fixed function name.
    } else if (**fmt == 'o') {
	unsigned long int num = va_arg(substitutes, unsigned long int);
	*chars_printed = myOct(&num);
    } else {
	stop("Invalid format specifier!");
    }

    return (*chars_printed);
}
