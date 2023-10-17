#include "main.h"

void handle_lf_case(const char **fmt, int *chars_printed, va_list substitutes)
{
    if (**fmt == 'l' && *(*fmt + 1) == 'f')
    {
	*chars_printed = (*printFunction[DOUBLE])(substitutes);
	*fmt += 2;
    }
}

void handle_switch_cases(const char **fmt, int *chars_printed, va_list substitutes) {
    switch (**fmt) {
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
	    *chars_printed = my_bin(&num);
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
		*chars_printed += (*printFunction[FLOAT])(substitutes);
	    (*fmt)++;
	    break;
	}
    }
}

void handle_other_cases(const char **fmt, int *chars_printed, va_list substitutes)
{
    switch (**fmt)
    {
	case 'r':
	{
	    char *str = va_arg(substitutes, char *);
	    chars_printed = (int *) string_reverse(str);
	    break;
	}
	case 'R':
	{
	    char *str = va_arg(substitutes, char *);
	    rot13(str);
	    break;
	}
	case 'S':
	    *chars_printed = handle_custom_s(substitutes);
	    break;
	default:
	    write(1, "%", 1);
	    write(1, &(**fmt), 1);
	    *chars_printed += 2;
    }
}


void handle_hash_case(const char **fmt, int *chars_printed, va_list substitutes)
{
    if (**fmt == '#')
    {
	++(*fmt);
	if (**fmt == 'x' || **fmt == 'X')
	{
	    unsigned long int num = va_arg(substitutes, unsigned long int);
	    *chars_printed = my_hex(*fmt, &num);
	}
	else if (**fmt == 'o')
	{
	    unsigned long int num = va_arg(substitutes, unsigned long int);
	    *chars_printed = my_oct(&num);
	}
	else
	{
	    stop("Invalid format specifier");
	}
    }
}
