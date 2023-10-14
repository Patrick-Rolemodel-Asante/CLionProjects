#include "main.h"



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
	int len = 0;
	char buffer[32]; // Assuming a maximum of 32 digits for an int

	// Handle negative numbers
	if (arg < 0) {
		char minus = '-';
		write(1, &minus, 1);
		arg = -arg; // Make arg positive for further processing
		len++;
	}

	// Convert the integer to a string
	int temp = arg;
	char int_str[32]; // Adjust the buffer size as needed
	int int_len = 0;

	if (temp == 0) {
		int_str[int_len++] = '0';
	} else {
		while (temp > 0) {
			int_str[int_len++] = '0' + (temp % 10);
			temp /= 10;
		}
	}

	for (int i = int_len - 1; i >= 0; i--) {
		write(1, &int_str[i], 1);
		len++;
	}

	return len;
}



int format_CHAR(va_list args) {
	char arg = va_arg(args, int); // Note: char is promoted to int
	write(1, &arg, 1);
	return (1);// Write the character to standard output
}



int format_STRING(va_list args) {
	char *arg = va_arg(args, char *);
	if (arg == NULL) stop("Format string is NULL");
	int len = 0;
	for (int i = 0; arg[i] != '\0' ; ++i, arg + i) {
		len++;
	}
	write(1, arg, len); // Write the string to standard output
	return (int) (len);
}




int format_FLOAT(va_list args) {
	double arg = va_arg(args, double);
	int len = 0;
	char buffer[64]; // Assuming a maximum of 64 characters for a float

	// Handle negative numbers
	if (arg < 0.0) {
		char minus = '-';
		write(1, &minus, 1);
		arg = -arg; // Make arg positive for further processing
		len++;
	}

	// Convert the integer part to a string
	int int_part = (int)arg;
	int temp = int_part;
	char int_str[64]; // Adjust the buffer size as needed
	int int_len = 0;

	if (temp == 0) {
		int_str[int_len++] = '0';
	} else {
		while (temp > 0) {
			int_str[int_len++] = '0' + (temp % 10);
			temp /= 10;
		}
	}

	for (int i = int_len - 1; i >= 0; i--) {
		write(1, &int_str[i], 1);
		len++;
	}

	// Print the decimal point
	char decimal_point = '.';
	write(1, &decimal_point, 1);
	len++;

	// Convert the fractional part to a string
	double frac_part = arg - int_part;
	int frac_len = 0;
	char frac_str[64]; // Adjust the buffer size as needed

	for (int i = 0; i < 6; i++) { // Six decimal places
		frac_part *= 10;
		int digit = (int)frac_part;
		frac_str[frac_len++] = '0' + digit;
		frac_part -= digit;
	}

	for (int i = 0; i < frac_len; i++) {
		write(1, &frac_str[i], 1);
		len++;
	}

	return len;
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

	return digits_printed; // Return the number of digits printed
}









int validate(const char *fmt, int *chars_printed, va_list substitutes){
	if (*fmt == 'l' && *(fmt + 1) == 'f') { // Handle long double
		*chars_printed = (*printFunction[DOUBLE])(substitutes); // Call the function for double
		fmt++; // Skip the next character because we've already processed it
	} else { //
		switch(*fmt) { // Handle the other format specifiers
			case '%': // Handle percent sign
				*chars_printed += (*printFunction[PERCENT])(substitutes);
				break;
			case '\n': // Handle newline
				*chars_printed = (*printFunction[PERCENT])(substitutes); // Call the function for percent sign
				break;
			case 'c': // Handle character
				*chars_printed = (*printFunction[CHAR])(substitutes); // Call the function for character
				break;
			case 's': // Handle string
				*chars_printed = (*printFunction[STRING])(substitutes); // Call the function for string
				break;
			case 'd': // Handle integer
				*chars_printed = (*printFunction[INT])(substitutes); // Call the function for integer
				break;
			case 'i': // Handle integer
				*chars_printed = (*printFunction[INT])(substitutes); // Call the function for integer
				break;
			case 'f':
				*chars_printed += (*printFunction[FLOAT])(substitutes);
				break;
			case 'X':{ // Handle hexadecimal
				unsigned long int num = va_arg(substitutes, unsigned long int);
				*chars_printed = write_me(&num, 16, 'X'); // Call the function for hexadecimal
				break;
			}
			case 'x': { // Handle hexadecimal small letter x
				unsigned long int num = va_arg(substitutes, unsigned long int);
				*chars_printed += write_me(&num, 16, 'x');
				break;
			}
			case 'o': {
				unsigned long int num = va_arg(substitutes, unsigned long int);
				*chars_printed = write_me(&num, 8, 'o');
				break;
			}
			case '#':{
				++fmt;
				if (*fmt == 'x' || *fmt == 'X') { // Handle hexadecimal with prefix
					unsigned long int num = va_arg(substitutes, unsigned long int);
					*chars_printed = my_hex(fmt, &num); // Call the function for hexadecimal with prefix
				} else if (*fmt == 'o') { // Handle octal with prefix
					unsigned long int num = va_arg(substitutes, unsigned long int);
					*chars_printed = my_oct(&num); // Call the function for octal with prefix
				} else {
					stop("Invalid format specifier");
				}
				break;
			}

		}
	}
	return (*chars_printed);
}





