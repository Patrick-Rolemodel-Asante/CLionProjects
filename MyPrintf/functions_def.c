#include "main.h"
//
// Created by rol on 10/7/23.
//
int (*printFunction[])(va_list) = {
        format_INT,
        format_CHAR,
        format_STRING,
        format_FLOAT,
        format_DOUBLE,
        format_PERCENT,
};


int format_INT(va_list args) {
    int arg = va_arg(args, int);
    char buffer[32]; // Assuming a maximum of 32 digits for an int
    int len = snprintf(buffer, sizeof(buffer), "%d", arg);
    if (len < 0) stop("No argument was passed to be inserted for the %d");
    write(1, buffer, len); // Write the integer to standard output
    return (len);
}


int format_CHAR(va_list args) {
    char arg = va_arg(args, int); // Note: char is promoted to int
    write(1, &arg, 1);
    return (1);// Write the character to standard output
}



int format_STRING(va_list args) {
    char *arg = va_arg(args, char *);
    if (arg == NULL) stop("Format string is NULL");
    size_t len = strlen(arg);
    write(1, arg, len); // Write the string to standard output
    return (int) (len);
}


int format_FLOAT(va_list args) {
    double arg = va_arg(args, double);
    char buffer[64]; // Assuming a maximum of 64 characters for a float
    int len = snprintf(buffer, sizeof(buffer), "%f", arg);
    write(1, buffer, len); // Write the float to standard output
    return (len);
}



int format_PERCENT(va_list empty) {
    char c = '%';
    write(1, &c, 1); // Write the percent sign to standard output
    return (1);
}



//int format_DOUBLE(va_list args) {
//    double arg = va_arg(args, double);
//    char buffer[64]; // Adjust the buffer size as needed
//    int len = snprintf(buffer, sizeof(buffer), "%.17f", arg);
//    write(1, buffer, len); // Write the double to standard output
//    return len;
//}



int format_DOUBLE(va_list args) {
    double arg = va_arg(args, double);
    int digits = 0;

    // Handle negative numbers
    if (arg < 0) {
        int written = write(1, "-", 1);
        if (written < 0) {
            perror("Error writing to standard output");
            return -1;
        }
        digits += written;
        arg = -arg; // Make arg positive for further processing
    }

    // Convert the integer part to a string
    int int_part = (int)arg;
    int int_digits = 1; // At least one digit
    int temp = int_part;
    while (temp >= 10) {
        temp /= 10;
        int_digits++;
    }
    char int_str[int_digits];
    snprintf(int_str, sizeof(int_str), "%d", int_part);

    int written = write(1, int_str, int_digits);
    if (written < 0) {
        perror("Error writing to standard output");
        return -1;
    }
    digits += written;

    // Print the decimal point
    written = write(1, ".", 1);
    if (written < 0) {
        perror("Error writing to standard output");
        return -1;
    }
    digits += written;

    // Convert the fractional part to a string
    double frac_part = arg - int_part;
    char frac_str[15]; // Adjust the buffer size as needed
    snprintf(frac_str, sizeof(frac_str), "%.6f", frac_part); // Six decimal places
    written = write(1, frac_str + 2, 7); // Skip the "0." part
    if (written < 0) {
        perror("Error writing to standard output");
        return -1;
    }
    digits += written;

    return digits;
}






int validate(const char *fmt, int *chars_printed, va_list substitutes){
    if (*fmt == 'l' && *(fmt + 1) == 'f') {
        *chars_printed += (*printFunction[DOUBLE])(substitutes);
        fmt++; // Skip the next character because we've already processed it
    } else {
        switch(*fmt) {
            case '%':
            case '\n':
                *chars_printed += (*printFunction[PERCENT])(substitutes);
                break;
            case 'c':
                *chars_printed += (*printFunction[CHAR])(substitutes);
                break;
            case 's':
                *chars_printed += (*printFunction[STRING])(substitutes);
                break;
            case 'd':
            case 'i':
                *chars_printed += (*printFunction[INT])(substitutes);
                break;
            case 'f':
                *chars_printed += (*printFunction[FLOAT])(substitutes);
                break;
            case 'X':
            case 'x': {
                unsigned long int num = va_arg(substitutes, unsigned long int);
                *chars_printed += my_hex(fmt, &num);
                break;
            }
            case 'o': {
                unsigned long int num = va_arg(substitutes, unsigned long int);
                *chars_printed += my_oct(fmt, &num);
                break;
            }
        }
    }
    return (*chars_printed);
}





