#include "main.h"

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _printf - This function prints a formatted string to the standard output.
 * Description: The _printf function is similar to the standard printf function
 * @format: A string containing zero or more format specifiers, which are
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;
	char buffer[1024];
	int buf_index = 0;

	if (format == NULL)
		return (1);

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			print_arg(format[i], args, buffer, &buf_index);
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
