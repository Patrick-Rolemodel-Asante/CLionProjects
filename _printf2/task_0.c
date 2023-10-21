//#include "main.h"
//
///**
// * _printf - prints anything
// * @format: list of types of arguments passed to the function
// *
// * Return: number of characters printed
// */
//
//int _printf(const char *format, ...)
//{
//	va_list args;
//	int charsPrinted = 0;
//	int i = 0;
//
//	va_start(args, format);
//
//	if (format == NULL)
//		return (-1);
//	while (format[i] != '\0')
//	{
//		if (format[i] == '%')
//		{
//			i++;
//			if (format[i] == '\0')
//				return (-1);
//			if (format[i] == '%')
//			{
//				write(1, &format[i], 1);
//				charsPrinted++;
//			} else if (format[i] == 'c')
//			{
//				charsPrinted += formatChar(args);
//			} else if (format[i] == 's')
//			{
//				charsPrinted += formatString(args);
//			} else
//			{
//				write(1, "%", 1);
//				write(1, &format[i], 1);
//				charsPrinted += 2;
//			}
//		} else
//		{
//			write(1, &format[i], 1);
//			charsPrinted++;
//		}
//		i++;
//	}
//	va_end(args);
//	return (charsPrinted);
//}
//
//
///**
// * formatString - prints a string
// * @list: list of arguments
// * Return: number of characters printed
// */
//
//int formatString(va_list list)
//{
//	char *str = va_arg(list, char *);
//	int i = 0;
//
//	if (str == NULL)
//	{
//		write(1, "(null)", 6);
//		return (6);
//	}
//
//	while (str[i] != '\0')
//	{
//		write(1, &str[i], 1);
//		i++;
//	}
//	return (i);
//}
//
//
///**
// * formatChar - prints a character
// * @list: list of arguments
// * Return: number of characters printed
// */
//int formatChar(va_list list)
//{
//	char c = va_arg(list, int);
//
//	write(1, &c, 1);
//	return (1);
//}
