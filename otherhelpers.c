#include "main.h"

/**
 * changeToBaseN - Convert a number to a different base
 * @num: The number to convert
 * @new_base: The new base for conversion
 *
 * Return: A string representing the number in the new base.
 */
char  *changeToBaseN(unsigned long int num, int new_base)
{
char all_nums[] = "0123456789ABCDEF";
char *res;

if (num < (unsigned long)new_base)
{
res = malloc(2);
res[0] = all_nums[num];
res[1] = '\0';
}
else
{
char *rem = changeToBaseN(num / new_base, new_base);
unsigned int len = strlen(rem);
res = malloc(len + 2);
strcpy(res, rem);
res[len] = all_nums[num % new_base];
res[len + 1] = '\0';
free(rem);
}
return (res);
}

/**
 * myBin - converts a number to binary
 * @num: number to convert
 *
 * Description: for binary conversion.
 * Return: number of characters printed
 */
int myBin(unsigned long *num)
{
char *new_num = changeToBaseN(*num, 2);
write(1, new_num, strlen(new_num));
free(new_num);
return ((int) strlen(new_num));
}

/**
 * myHex - converts a number to hexadecimal
 * @fmt: format specifier
 * @num: number to convert
 *
 * Description: for hexadecimal conversion.
 * Return: number of characters printed
 */
int myHex(char *fmt, unsigned long num)
{
int total_length = 0;
char prefix_low[] = "0x";
char prefix_upp[] = "0X";
char *new_num = changeToBaseN(num, 16);

if (*fmt == 'x')
{
lower_case(new_num);
write(1, prefix_low, strlen(prefix_low));
}
else if (*fmt == 'X')
{
write(1, prefix_upp, strlen(prefix_upp));
}
write(1, new_num, strlen(new_num));
total_length = (int)(strlen(new_num) + strlen(prefix_low));
free(new_num);
return (total_length);
}

/**
 * myOct - converts a number to octal
 * @*num: number to convert
 *
 * Description: for octal numbers
 * Return: number of characters printed
 */
int myOct(unsigned long *num)
{
char prefix_upp[] = "0";
char *new_num = changeToBaseN(*num, 8);

strcpy(prefix_upp + 1, new_num);
write(1, prefix_upp, strlen(prefix_upp));

free(new_num);
return ((int)(strlen(prefix_upp) - 1));
}


/**
 * writeMe - writes the number to the standard output
 * @num: number to write
 * @base: base to convert to
 * @letter: letter to use
 *
 * Description: writes numbers to stdout
 * Return: number of characters printed
 */
int writeMe(unsigned long *num, int base, char letter)
{
char *new_num = changeToBaseN(*num, base);
int new_num_len = (int)(strlen(new_num));

if (letter == 'x')
{
lower_case(new_num);
}
write(1, new_num, new_num_len);
free(new_num);
return (new_num_len);
}
