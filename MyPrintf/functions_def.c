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




int format_DOUBLE(va_list args) {
    double arg = va_arg(args, double);
    int digits_printed = 0;

    // Handle negative numbers
    if (arg < 0) {
        write(1, "-", 1);
        digits_printed++;
        arg = -arg; // Make arg positive for further processing
    }


    // Convert the integer part to a string
    int int_part = (int)arg;
    char* int_str = malloc(int_part * sizeof(char)); // Adjust the buffer size as needed
    if (int_str == NULL) {
        stop("Error allocating memory");
    }
    int i = 0;
    do {
        int_str[i++] = '0' + (int_part % 10); // Get the rightmost digit
        int_part /= 10; // Remove the rightmost digit
    } while (int_part != 0);
    int_str[i] = '\0'; // Add the null terminator

    // Reverse the string from the do-while loop above
    for (int j = 0; j < i / 2; j++) {
        char temp = int_str[j]; // Store the left character in a temporary variable
        int_str[j] = int_str[i - j - 1]; // Replace the left character with the right character
        int_str[i - j - 1] = temp; // Replace the right character with the stored left character
    }

    write(1, int_str, i);
    digits_printed += i; // Increment the number of digits printed

    // Print the decimal point
    write(1, ".", 1);
    digits_printed++; // Increment the number of digits printed

    // Convert the fractional part to a string
    double frac_part = arg - int_part; // Get the fractional part
    char frac_str[7]; // Adjust the buffer size as needed
    for (i = 0; i < 6; i++) {  // Print up to 6 digits
        frac_part *= 10; // Shift the decimal point
        frac_str[i] = '0' + ((int)frac_part % 10); // Get the rightmost digit
        frac_part -= (int)frac_part; // Remove the rightmost digit
    }
    frac_str[6] = '\0'; // Add the null terminator

    write(1, frac_str, 6);
    digits_printed += 6;

    free(int_str);

    return digits_printed;
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
            case 'X':{
                unsigned long int num = va_arg(substitutes, unsigned long int);
                *chars_printed += write_me(&num, 16, 'X');
                break;
            }
            case 'x': {
                unsigned long int num = va_arg(substitutes, unsigned long int);
                *chars_printed += write_me(&num, 16, 'x');
                break;
            }
            case 'o': {
                unsigned long int num = va_arg(substitutes, unsigned long int);
                *chars_printed += write_me(&num, 8, 'o');
                break;
            }
            case '#':{
                ++fmt;
                if (*fmt == 'x' || *fmt == 'X') {
                    unsigned long int num = va_arg(substitutes, unsigned long int);
                    *chars_printed = my_hex(fmt, &num);
                } else if (*fmt == 'o') {
                    unsigned long int num = va_arg(substitutes, unsigned long int);
                    *chars_printed = my_oct(&num);
                } else {
                    stop("Invalid format specifier");
                }
                break;
            }

        }
    }
    return (*chars_printed);
}





