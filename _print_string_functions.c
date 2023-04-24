#include "main.h"

#include <unistd.h>
#include <stdio.h>

/**
 * print_char -  prints a character
 * @args: The va_list of arguments to format.
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_char(va_list args, char *buffer, int *buf_index)
{
	char c;
	
	c = va_arg(args, int);
	buffer[(*buf_index)++] = c;
}

/**
 * print_string -  prints string
 * @args: The va_list of arguments to format.
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_string(va_list args, char *buffer, int *buf_index)
{
	char *s, hex[5] = {0};
	int high, low, ascii;
	
	s = va_arg(args, char *);
	if (s == NULL)
	{
		char *nil_str = "(nil)";
		while (*nil_str)
			buffer[(*buf_index)++] = *nil_str++;
		return;
	}
	while (*s)
	{
		ascii = (int)*s;
		if (ascii < 32 || ascii >= 127)
		{
			high = ascii / 16;
			low = ascii % 16;
			hex[0] = '\\';
			hex[1] = 'x';
			hex[2] = (high > 9) ? 'A' + (high - 10) : '0' + high;
			hex[3] = (low > 9) ? 'A' + (low - 10) : '0' + low;
			buffer[(*buf_index)++] = hex[0];
			buffer[(*buf_index)++] = hex[1];
			buffer[(*buf_index)++] = hex[2];
			buffer[(*buf_index)++] = hex[3];
		}
		else
			buffer[(*buf_index)++] = *s;
		s++;
	}
}

/**
 * print_percent -  prints %
 * @args: The va_list of arguments to format.
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_percent(va_list args, char *buffer, int *buf_index)
{
	UNUSED(args);
	buffer[(*buf_index)++] = '%';
}
