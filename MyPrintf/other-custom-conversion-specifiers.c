#include "main.h"

/**
* address - handles the custom specifier 'p'
* @num: the number to convert
*
* Return: the number of characters printed
*/

int address(const long *num)
{
	char *newNum = changeToBaseN(*num, 16);

	if (!newNum)
		stop("Memory allocation error");

	char prefixLow[300] = "0x";

	lowerCase(newNum);
	write(1, prefixLow, strlen(prefixLow));
	write(1, newNum, strlen(newNum));

	int totalLength = (int) (strlen(prefixLow) + strlen(newNum));

	free(newNum);
	return (totalLength);

}


/**
* handleCustomS - handles the custom specifier S
* @substitutes: the list of arguments
*
* Return: the number of characters printed
*/

int handleCustomS(va_list substitutes)
{
	char *str = va_arg(substitutes, char *); /* get the string */
	int len = 0; /* length of the string */
	int i;
	char *hex;
	char *temp;
	char *temp2;

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
		if (str[i] < 32 || str[i] >= 127)
			len += 4;
		else
			len++;
	temp = malloc(sizeof(char) * (len + 1));
	temp2 = temp;
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			*temp++ = '\\';
			*temp++ = 'x';
			hex = convertToHex(str[i]);
			*temp++ = hex[0];
			*temp++ = hex[1];
			free(hex);
		}
		else
			*temp++ = str[i];
	}
	*temp = '\0';
	len = write(1, temp2, len);
	free(temp2);
	return (len);
}

/**
* convertToHex - converts a number to hexadecimal
* @num: the number to convert
*
* Return: the hexadecimal number
*/

char *convertToHex(int num)
{
	int i;
	char *hex = malloc(sizeof(char) * 3);

	for (i = 1; i >= 0; i--)
	{
		if (num % 16 > 9)
			hex[i] = (num % 16) + 55;
		else
			hex[i] = (num % 16) + '0';
		num /= 16;
	}
	return (hex);
}

/**
* formatPercent - prints a percent sign
* Return: number of characters printed
*/

int formatPercent(void)
{
	write(1, "%", 1);
	return (1);
}

/**
* formatUnsigned - prints an unsigned integer
* @args: list of arguments
* Return: number of characters printed
*/

int formatUnsigned(va_list args)
{
	unsigned int arg = va_arg(args, unsigned int);

	char int_str[32];
	int int_len = 0;

	if (arg == 0)
		int_str[int_len++] = '0';
	else
	{
		while (arg > 0 && int_len < 32)
		{
			int_str[int_len++] = '0' + (arg % 10);
			arg /= 10;
		}
	}

	for (int i = int_len - 1; i >= 0; i--)
		write(1, &int_str[i], 1);

	return (int_len);
}
