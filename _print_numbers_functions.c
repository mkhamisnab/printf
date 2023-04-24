#include "main.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_address -  prints address
 * @args: The va_list of arguments to format.
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_address(va_list args, char *buffer, int *buf_index)
{
	char *adr = NULL, *temp_adr_buff;
	int j;
	
	adr = va_arg(args, void *);
	temp_adr_buff = (char *)malloc(sizeof(adr) * 2 + 1);
	sprintf(temp_adr_buff, "%p", adr);
	for (j = 0; temp_adr_buff[j] != '\0'; j++)
		buffer[(*buf_index)++] = temp_adr_buff[j];
	free(temp_adr_buff);
}

/**
 * print_binary -  calculates binary of a number
 * @args: The va_list of arguments to format.
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_binary(va_list args, char *buffer, int *buf_index)
{
	unsigned int n, i, sum;
	unsigned long m;
	unsigned int a[32];
    int count;
	
	UNUSED(buffer);
	UNUSED(buf_index);
	
	n = va_arg(args, unsigned int);
	if (!n)
	{
		write(1, "(nil)", 5);
		return;
	}
	m = 2147483648UL;
	a[0] = n / m;
	i = 1;
	while (i < 32)
	{
		m /= 2;
		a[i] = (n / m) % 2;
		i++;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];
			write(1, &z, 1);
			count++;
		}
	}
}

/**
 * print_unsigned_integer - Helper function to print an unsigned integer in base 8, 10, or 16
 * @num: number
 * @base: base
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_unsigned_integer(unsigned int num, int base, char *buffer, int *buf_index)
{
	char digits[16] = "0123456789abcdef";
	char result[20];
	int digit_index = 0;
	
	if (num == 0)
	{
		buffer[(*buf_index)++] = '0';
		return;
	}
	
	while (num != 0)
	{
		result[digit_index++] = digits[num % base];
		num /= base;
	}
	while (digit_index > 0)
	{
		buffer[(*buf_index)++] = result[--digit_index];
	}
}

/**
 * print_int - Implementation of the %d and %i format specifiers
 * @args: The va_list of arguments to format.
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_int(va_list args, char *buffer, int *buf_index)
{
	int num = va_arg(args, int);
	if (num < 0)
	{
		buffer[(*buf_index)++] = '-';
		num = -num;
	}
	print_unsigned_integer((unsigned int)num, 10, buffer, buf_index);
}

/**
 * print_octal - Implementation of the %o format specifier
 * @args: The va_list of arguments to format.
 * @buffer: A buffer to write the printed integer to
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_octal(va_list args, char *buffer, int *buf_index)
{
	unsigned int num = va_arg(args, unsigned int);
	print_unsigned_integer(num, 8, buffer, buf_index);
}

/**
 * print_unsigned - Implementation of the %u format specifier
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
 * @map_to: The array of characters to map hexadecimal digits to
 * @buffer: A buffer to write the printed integer to
 * @flag_ch: The flag character
 * @buf_index: A pointer to the current index of the buffer
 *
 * Return: void
 */
void print_hexa(va_list args, char map_to[], char *buffer, char flag_ch, int *buf_index)
{
	int i;
	unsigned int num;
	
	UNUSED(flag_ch);
	
	i = BUFFER_SIZE - 2;
	num = va_arg(args, unsigned int);
	
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFFER_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	
	for (i = i + 1; i < BUFFER_SIZE - 1; i++)
	{
		buffer[*buf_index] = buffer[i];
		(*buf_index)++;
	}
}