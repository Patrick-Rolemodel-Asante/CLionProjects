#include "main.h"

/**
 * unsignedToSigned - converts an unsigned int to a signed int
 * @num: number to convert
 * Return: converted signed number
 */

char *unsignedToSigned(unsigned int num)
{
	char allNums[] = "0123456789"; /* 0-9 */
	char *res; /* result */

	if (num < 10) /* if num is less than 10 */
	{
		res = malloc(2); /* allocate memory for 2 chars */
		res[0] = allNums[num]; /* set first char to num */
		res[1] = '\0'; /* set second char to null byte */
	}
	else /* if num is greater than or equal to 10 */
	{
		char *rem = unsignedToSigned(num / 10); /* convert num / 10 */
		unsigned int len = _strlen(rem); /* get length of rem */

		res = malloc(len + 2); /* allocate memory for len + 2 chars */
		_strcpy(res, rem); /* copy rem to res */
		res[len] = allNums[num % 10]; /* set last char to num % 10 */
		res[len + 1] = '\0'; /* set second to last char to null byte */
		free(rem); /* free rem */
		write(1, res, _strlen(res));
	}
	return (res); /* return res */
}


/**
 * unsignedIntToOct - converts an unsigned int to octal
 * @num: number to convert
 * Return: converted octal number
 */


char *unsignedIntToOct(unsigned int *num)
{
	char *res = changeToBaseN(num, 8); /* convert num to base 8 */

	write(1, res, _strlen(res));
	return (res); /* return res */

}

/**
 * unsignedIntToHex - converts an unsigned int to hexadecimal
 * @num: number to convert
 * Return: converted hexadecimal number
 */

char *unsignedIntToHex(unsigned int *num)
{
	char *res = changeToBaseN(num, 16); /* convert num to base 16 */

	write(1, res, _strlen(res));
	return (res); /* return res */
}
