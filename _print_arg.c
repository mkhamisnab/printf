#include "main.h"

#include <stdarg.h>
#include <stdlib.h>
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
	int j, number;
	char *binary, *string, character;

	switch (specifier)
	{
	case 'c':
		character = (char)va_arg(args, int);
		buffer[(*buf_index)++] = character;
		break;
	case 's':
		string = va_arg(args, char *);
		for (j = 0; string[j] != '\0'; j++)
			buffer[(*buf_index)++] = string[j];
		break;
	case '%':
		buffer[(*buf_index)++] = '%';
		break;
	case 'b':
		number = va_arg(args, int);
		binary = cal_binary(number);
		for (j = 0; binary[j] != '\0'; j++)
			buffer[(*buf_index)++] = binary[j];
		free(binary);
		break;
	}
}
