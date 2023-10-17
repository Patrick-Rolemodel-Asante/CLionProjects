#include "main.h"

/**
 * handle_custom_r - handles the custom specifier r
 * @substitutes: the list of arguments
 *
 * Return: the number of characters printed
 */

int handle_address(const char *fmt, unsigned long *num) {
    char *new_num = change_to_baseN(*num, 16);

    if (!new_num) {
        // Handle memory allocation error.
        stop("Memory allocation error");
    }
    char prefix_low[300] = "0x";
    lower_case(new_num);
    write(1, prefix_low, strlen(prefix_low));
    write(1, new_num, strlen(new_num));
    int total_length = (int) (strlen(prefix_low) + strlen(new_num));
    free(new_num);  // Remember to free the memory allocated in change_to_baseN.
    return total_length;

}


/**
 * handle_custom_s - handles the custom specifier S
 * @substitutes: the list of arguments
 *
 * Return: the number of characters printed
 */

int handle_custom_s(va_list substitutes) {
    char *str = va_arg(substitutes, char *);
    int len = 0;
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
    for (i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            *temp++ = '\\';
            *temp++ = 'x';
            hex = convert_to_hex(str[i]);
            *temp++ = hex[0];
            *temp++ = hex[1];
            free(hex);
        } else
            *temp++ = str[i];
    }
    *temp = '\0';
    len = write(1, temp2, len);
    free(temp2);
    return (len);
}

/**
 * convert_to_hex - converts a number to hexadecimal
 * @num: the number to convert
 *
 * Return: the hexadecimal number
 */

char *convert_to_hex(int num) {
    int i;
    char *hex = malloc(sizeof(char) * 3);

    for (i = 1; i >= 0; i--) {
        if (num % 16 > 9)
            hex[i] = (num % 16) + 55;
        else
            hex[i] = (num % 16) + '0';
        num /= 16;
    }
    return (hex);
}

/**
 * format_PERCENT - prints a percent sign
 * @empty: list of arguments
 * Return: number of characters printed
 */

int format_PERCENT(va_list empty)
{
    write(1, "%", 1);
    return (1);
}

/**
 * format_UNSIGNED - prints an unsigned integer
 * @args: list of arguments
 * Return: number of characters printed
 */

int format_UNSIGNED(va_list args)
{
    unsigned int arg = va_arg(args, unsigned int);  // Use unsigned int

    char int_str[32];
    int int_len = 0;

    if (arg == 0) {
	int_str[int_len++] = '0';
    }
    else {
	while (arg > 0 && int_len < 32) {
	    int_str[int_len++] = '0' + (arg % 10);
	    arg /= 10;
	}
    }

    for (int i = int_len - 1; i >= 0; i--) {
	write(1, &int_str[i], 1);
    }

    return int_len;  // Return the length of the formatted string
}
