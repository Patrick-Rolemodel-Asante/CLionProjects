#include "main.h"

/**
 * validate - validates the format specifier
 * @fmt: format specifier
 * @chars_printed: number of characters printed
 * @substitutes: list of arguments
 * Return: number of characters printed
 */

int validate(const char *fmt, int *chars_printed, va_list substitutes)
{
handle_lf_case(&fmt, chars_printed, substitutes);
handle_switch_cases(&fmt, chars_printed, substitutes);
handle_hash_case(&fmt, chars_printed, substitutes);
handle_other_cases(&fmt, chars_printed, substitutes);

return (*chars_printed);
}
