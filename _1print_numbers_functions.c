#include "main.h"

#include <unistd.h>
#include <stdio.h>

/**
ii * print_unsigned - Implementation of the %u format specifier
 * @args: The va_list of arguments to format.
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_unsigned(va_list args, char *buffer, int *buf_index)
{
	unsigned int num = va_arg(args, unsigned int);

	print_unsigned_integer(num, 10, buffer, buf_index);
}
/**
 * print_hex_lower - Implementation of the %x format specifier
 * @args: The va_list of arguments to format.
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_hex_lower(va_list args, char *buffer, int *buf_index)
{
	print_hexa(args, "0123456789abcdef", buffer, 'x', buf_index);
}

/**
 * print_hex_upper - Implementation of the %X format specifier
 * @args: The va_list of arguments to format.
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_hex_upper(va_list args, char *buffer, int *buf_index)
{
	print_hexa(args, "0123456789ABCDEF", buffer, 'X', buf_index);
}

/**
 * print_hexa - Prints an unsigned integer as a hexadecimal number
 * @args: The va_list of arguments to format.
 * @map_to: The array of characte* @buffer: A buffer to write the printed integer to
 * @flag_ch: The flag character
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_hexa(va_list args, char map_to[],

 char *buffer, char flag_ch, int *buf_index)
{
	int i;
	unsigned int num;
}
