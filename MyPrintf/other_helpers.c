#include "main.h"
/**
* changeToBaseN - changes a num to new base
* @num: the number to be changed
* @newBase: the base to change to
* Return: new num in new base
*/
char  *changeToBaseN(unsigned long int num, int newBase)
{
	char allNums[] = "0123456789ABCDEF";
	char *res;

	if (num < newBase)
	{
		res = malloc(2);
		res[0] = allNums[num];
		res[1] = '\0';
	}
	else
	{
		char *rem = changeToBaseN(num / newBase, newBase);
		unsigned int len = strlen(rem);

		res = malloc(len + 2);
		strcpy(res, rem);
		res[len] = allNums[num % newBase];
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

int myBin(const unsigned long *num)
{
	char *newNum = changeToBaseN(*num, 2);

	write(1, newNum, strlen(newNum));
	return ((int) strlen(newNum));
}


/**
* myHex - converts a number to hexadecimal
* @fmt: format specifier
* @num: number to convert
* Return: number of characters printed
*/
int myHex(const char *fmt, const unsigned long *num)
{
	char *newNum = changeToBaseN(*num, 16);

	if (!newNum)
		stop("Memory allocation error");

	if (*fmt == 'x')
	{
		char prefixLow[300] = "0x";

		lowerCase(newNum);
		write(1, prefixLow, strlen(prefixLow));
		write(1, newNum, strlen(newNum));
		int totalLength = (int) (strlen(prefixLow) + strlen(newNum));

		free(newNum);
		return (totalLength);
	}
	char prefixUpp[300] = "0X";

	strncat(prefixUpp, newNum, strlen(newNum));
	write(1, prefixUpp, strlen(prefixUpp));
	int totalLength = (int) strlen(prefixUpp);

	free(newNum);
	return (totalLength - 1);
}


/**
* myOct - converts a number to octal
* @num: number to convert
* Return: number of characters printed
*/
int myOct(const unsigned long *num)
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
int writeMe(const long *num, int base, char letter)
{
	char *newNum = changeToBaseN(*num, base);

	if (letter == 'x')
		lowerCase(newNum);

	int newNumLen = (int) (strlen(newNum));

	write(1, newNum, newNumLen);

	free(newNum);
	return (newNumLen);
}
