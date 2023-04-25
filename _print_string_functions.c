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
/**
 * print_reverse - prints a string in reverse order
 * @args: The va_list of arguments to format.
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_reverse(va_list args, char *buffer, int *buf_index)
{
	char *s;
	int len, i;
	
	s = va_arg(args, char *);
	if (s == NULL)
	{
		char *nil_str = "(nil)";
		while (*nil_str)
			buffer[(*buf_index)++] = *nil_str++;
		return;
	}
	len = 0;
	while (s[len] != '\0')
		len++;
	for (i = len - 1; i >= 0; i--)
		buffer[(*buf_index)++] = s[i];
}
/**
 * print_rot13 - prints a string encoded with rot13 substitution cipher
 * @args: The va_list of arguments to format.
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_rot13(va_list args, char *buffer, int *buf_index)
{
	char *s;
	int i, j;
	
	char *rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	char *alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	
	s = va_arg(args, char *);
	if (s == NULL)
	{
		char *nil_str = "(nil)";
		while (*nil_str)
			buffer[(*buf_index)++] = *nil_str++;
		return;
	}
	for (i = 0; s[i]; i++)
	{
		for (j = 0; alphabet[j]; j++)
		{
			if (s[i] == alphabet[j])
			{
				buffer[(*buf_index)++] = rot13[j];
				break;
			}
		}
		if (!alphabet[j])
			buffer[(*buf_index)++] = s[i];
	}
}
