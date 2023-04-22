#include "main.h"

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - This function prints a formatted string to the standard output.
 * Description: _printf function is similar to the standard printf function
 * @format: A string containing zero or more format specifiers
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j, number;
	int count = 0;
	char *binary;
	char *string;
	char character, specifier;
	char buffer[1024];
	int buf_index = 0;

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			specifier = format[i];

			switch (specifier)
			{
			case 'c':
				character = (char)va_arg(args, int);
				buffer[buf_index++] = character;
				break;
			case 's':
				string = va_arg(args, char *);
				for (j = 0; string[j] != '\0'; j++)
					buffer[buf_index++] = string[j];
				break;
			case '%':
				buffer[buf_index++] = '%';
				break;
			case 'b':
				number = va_arg(args, int);
				binary = cal_binary(number);
				for (j = 0; binary[j] != '\0'; j++)
					buffer[buf_index++] = binary[j];
				free(binary);
				break;
			}
		}
		else
			buffer[buf_index++] = format[i];

		if (buf_index >= 1024)
		{
			count += write(STDOUT_FILENO, buffer, buf_index);
			buf_index = 0;
		}
		i++;
	}
	if (buf_index > 0)
		count += write(STDOUT_FILENO, buffer, buf_index);
	va_end(args);
	return (count);
}
