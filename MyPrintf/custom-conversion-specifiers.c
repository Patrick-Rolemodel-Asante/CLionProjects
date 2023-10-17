#include "main.h"

/**
 * rot13 - Encodes a string using the rot13 algorithm.
 * @s: The string to be encoded.
 *
 * This function encodes a string using the rot13 algorithm.
 */
void rot13(char *s)
{
    int i = 0;

    while (s[i] != '\0')
    {
	if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
	    s[i] += 13;
	else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
	{
	    s[i] -= 13;
	    i++;
	}
    }
}

/**
 * string_reverse - Reverses a string.
 * @str: The string to be reversed.
 *
 * This function reverses the characters in a string.
 *
 * Return: The length of the string.
 */
int string_reverse(char *str)
{
    int i = 0;
    int len = 0;
    char temp;

    while (str[i] != '\0')
    {
	len++;
	i++;
    }

    for (i = 0; i < len / 2; i++)
    {
	temp = str[i];
	str[i] = str[len - i - 1];
	str[len - i - 1] = temp;
    }

    return (len);
}

/**
 * lowerCase - Converts uppercase letters to lowercase in a string.
 * @new_num: The string to convert.
 *
 * This function converts uppercase letters in a string to lowercase.
 */
void lowerCase(char *new_num)
{
    int i = 0;

    while (new_num[i] != '\0')
    {
	if (new_num[i] >= 'A' && new_num[i] <= 'Z')
	    new_num[i] += 32;
	i++;
    }
}
