#include "main.h"

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * print_arg - This function handles the formatting of a single argument.
 * @specifier: The format specifier character (e.g. 'c', 's', '%', 'b').
 * @args: The va_list of arguments to format.
 * @buffer: The buffer to write the formatted output to.
 * @buf_index: A pointer to the current index in the buffer.
 * Return: None
 */
void print_arg(char specifier, va_list args, char *buffer, int *buf_index)
{
	int i = 0;
	
	fmt_t fmt_types[] = {
		{'c', print_char},
		{'s', print_string},
		{'S', print_string},
		{'r', print_reverse},
		{'R', print_rot13},
		{'%', print_percent},
		{'d', print_int},
		{'i', print_int},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		{'p', print_address},
		{'\0', NULL}};

	while (fmt_types[i].specifier != '\0')
	{
		if (fmt_types[i].specifier == specifier)
		{
			fmt_types[i].print_func(args, buffer, buf_index);
			return;
		}
		i++;
	}

		if (specifier != ' ' && specifier != '\0')
		{
			buffer[(*buf_index)++] = '%';
			buffer[(*buf_index)++] = specifier;
		}
}
