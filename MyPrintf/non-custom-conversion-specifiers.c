#include "main.h"

/**
* printFunction - an array of function pointers
 * @printFunction: function pointer
* Return: number of characters printed
*/
int (*printFunction[])(va_list) = {
format_INT,
format_CHAR,
format_STRING,
format_PERCENT,
format_UNSIGNED
};

/**
* format_INT - prints an integer
* @args: list of arguments
* Return: number of characters printed
*/

int format_INT(va_list args)
{
int arg = va_arg(args, int);
int len = 0;
if (arg < 0)
{
write(1, "-", 1);
len++;
arg = -arg;
}

int temp = arg;
char int_str[32];
int int_len = 0;

if (temp == 0)
int_str[int_len++] = '0';
else
{
while (temp > 0)
{
int_str[int_len++] = '0' + (temp % 10);
temp /= 10;
}
}

for (int i = int_len - 1; i >= 0; i--)
{
write(1, &int_str[i], 1);
len++;
}

return (len);
}


/**
* format_CHAR - prints a character
* @args: list of arguments
* Return: number of characters printed
*/

int format_CHAR(va_list args)
{
char arg = va_arg(args, int);
write(1, &arg, 1);
return (1);
}

/**
* format_STRING - prints a string
* @args: list of arguments
* Return: number of characters printed
*/

int format_STRING(va_list args)
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

/**
 * format_floating_number - prints a floating number
 * @args: list of arguments
 * @flag: flag
 * Return: number of characters printed
 */


int format_floating_number(va_list args, int flag)
{
double arg = flag ? va_arg(args, double) : va_arg(args, double);
int digits_printed = 0;

if (arg < 0)
{
write(1, "-", 1);
digits_printed++;
arg = -arg;
}

int int_part = (int) arg;
char *int_str = malloc(int_part * sizeof(char));
if (int_str == NULL)
stop("Error allocating memory");
int i = 0;
do {
int_str[i++] = '0' + (int_part % 10);
int_part /= 10;
} while (int_part != 0);

int_str[i] = '\0';
for (int j = 0; j < i / 2; j++)
{
char temp = int_str[j];
int_str[j] = int_str[i - j - 1];
int_str[i - j - 1] = temp;
}

write(1, int_str, i);
digits_printed += i;

write(1, ".", 1);
digits_printed++;

double frac_part = arg - int_part;
char frac_str[7];
for (i = 0; i < 6; i++)
{
frac_part *= 10;
frac_str[i] = '0' + ((int) frac_part % 10);
frac_part -= (int) frac_part;
}
frac_str[6] = '\0';

write(1, frac_str, 6);
digits_printed += 6;

free(int_str);

return (digits_printed);
}
