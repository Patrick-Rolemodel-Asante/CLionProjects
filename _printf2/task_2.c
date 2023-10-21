#include "main.h"

/**
 * changeToBaseN - converts a number to any base
 * @num: number to convert
 * @newBase: base to convert to
 * Return: number in new base
 */

char *changeToBaseN(unsigned int *num, int newBase)
{
	char allNums[] = "0123456789ABCDEF";
	char *res;

	if (*num < (unsigned int) newBase)
	{
		res = malloc(2);
		res[0] = allNums[*num];
		res[1] = '\0';
	}
	else
	{
		unsigned int remainder = *num / newBase;
		char *rem = changeToBaseN(&remainder, newBase);
		unsigned int len = _strlen(rem);

		res = malloc(len + 2);
		_strcpy(res, rem);
		res[len] = allNums[*num % newBase];
		res[len + 1] = '\0';
		free(rem);
	}

	return (res);
}

/**
 * _strlen - finds the length of a string
 * @rem: string to find length of
 * Return: length of string
 */
unsigned int _strlen(char *rem)
{
	unsigned int len = 0;

	while (rem[len] != '\0')
		len++;

	return (len);
}

/**
 * _strcpy - copies a string
 * @res: destination string
 * @rem: string to copy
 */
void _strcpy(char *res, char *rem)
{
	int i = 0;

	while (rem[i] != '\0')
	{
		res[i] = rem[i];
		i++;
	}
	res[i] = '\0';

}


/**
 * unsignedIntToBinary - converts a number to binary
 * @num: number to convert
 * Return: number of characters printed
 */

int unsignedIntToBinary(unsigned int *num)
{
	char *newNum = changeToBaseN(num, 2);

	write(1, newNum, _strlen(newNum));
	return ((int) _strlen(newNum));
}
