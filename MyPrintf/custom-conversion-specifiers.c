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
char c;

while (s[i] != '\0')
{
if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
{
c = s[i] + 13;
write(1, &c, 1);
i++;
}
else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
{
c = s[i] - 13;
write(1, &c, 1);
i++;
}
else
{
write(1, &s[i], 1);
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

while (str[i] != '\0')
{
len++;
i++;
}
char *rev = malloc(len + 1);
if (rev == NULL)
return (-1);
for (i = 0; i < len; i++)
{
rev[i] = str[len - i - 1];
}
rev[len] = '\0';
write(1, rev, len);
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
