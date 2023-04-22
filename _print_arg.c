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
	int j, number;
	char *binary, *string, character;
	char *adr = NULL, *temp_adr_buff;

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
	case 'p':
		adr = va_arg(args, void *);
		temp_adr_buff = (char *)malloc(sizeof(adr) * 2 + 1);
		sprintf(temp_adr_buff, "%p", adr);
		for (j = 0; temp_adr_buff[j] != '\0'; j++)
			buffer[(*buf_index)++] = temp_adr_buff[j];
		free(temp_adr_buff);
		break;
	default:
		if (specifier != ' ' && specifier != '\0')
		{
			buffer[(*buf_index)++] = '%';
			buffer[(*buf_index)++] = specifier;
		}
	}
}
