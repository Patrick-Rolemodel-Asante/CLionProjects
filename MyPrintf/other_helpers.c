#include "main.h"
/**
 * changeToBaseN - changes a num to new base
 * @num: the number to be changed
 * @new_base: the base to change to
 * Return: new num in new base
 */
char  *changeToBaseN(unsigned long int num, int new_base)
{
    char all_nums[] = "0123456789ABCDEF";
    char *res;

    if (num < new_base)
    {
	res = malloc(2);
	res[0] = all_nums[num];
	res[1] = '\0';
    } else
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
 * Return: number of characters printed
 */
int myHex(char *fmt, unsigned long *num)
{
    char *new_num = changeToBaseN(*num, 16);

    if (!new_num)
	stop("Memory allocation error");

    if (*fmt == 'x')
    {
	char prefix_low[300] = "0x";
	lowerCase(new_num);
	write(1, prefix_low, strlen(prefix_low));
	write(1, new_num, strlen(new_num));
	int total_length = (int) (strlen(prefix_low) + strlen(new_num));
	free(new_num);
	return (total_length);
    }

    char prefix_upp[300] = "0X";
    strncat(prefix_upp, new_num, strlen(new_num));
    write(1, prefix_upp, strlen(prefix_upp));
    int total_length = (int) strlen(prefix_upp);
    free(new_num);
    return (total_length - 1);
}


/**
 * myOct - converts a number to octal
 * @num: number to convert
 * Return: number of characters printed
 */
int myOct(unsigned long *num)
{
    char *newNum = changeToBaseN(*num, 8);
    char prefixUpp[300] = "0";
    strncat(prefixUpp, newNum, strlen(newNum) + 2);
    write(1, prefixUpp, strlen(prefixUpp));

    free(newNum);
    return ((int) (strlen(prefixUpp) - 1));
}


/**
 * writeMe - writes the number to the standard output
 * @num: number to write
 * @base: base to convert to
 * @letter: letter to use
 * Return: number of characters printed
 */
int writeMe(unsigned long *num, int base, char letter)
{
    char *newNum = changeToBaseN(*num, base);
    if (letter == 'x')
	lowerCase(newNum);
    int newNumLen = (int) (strlen(newNum));
    write(1, newNum, newNumLen);

    free(newNum);
    return (newNumLen);
}
