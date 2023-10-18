#include "main.h"

int handleLfCase(char **fmt, int *chars_printed, va_list substitutes)
{
*chars_printed = format_floating_number(substitutes, 1);
return (*chars_printed);
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
case 'b': {
unsigned long int num = va_arg(substitutes, unsigned long int);
*chars_printed = myBin(&num);
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
*chars_printed += format_floating_number(substitutes, 0);
break;
}
case 'X':
case 'x':
{
if (*fmt == 'x')
{
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
case 'p':
{
unsigned long int num = va_arg(substitutes, unsigned long int);
*chars_printed = handleAddress(fmt, &num);
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


int handleSCase(char **fmt, int *chars_printed, va_list substitutes)
{
return (*chars_printed = handleCustomS(substitutes));
}


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
