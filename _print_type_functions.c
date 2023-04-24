#include "main.h"

#include <unistd.h>

void print_char(va_list args, char *buffer, int *buf_index)
{
	char c;

	c = va_arg(args, int);
	buffer[(*buf_index)++] = c;
}

void print_string(va_list args, char *buffer, int *buf_index)
{
	char *s;

	s = va_arg(args, char *);
	while (*s)
		buffer[(*buf_index)++] = *s++;
}

void print_percent(va_list args, char *buffer, int *buf_index)
{
	buffer[(*buf_index)++] = '%';
}

/**
 * print_binary -  calculates binary of a number
 * @num: number
 * Return: binary
 */

void print_binary(va_list args, char *buffer, int *buf_index)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(buf_index);

	n = va_arg(args, unsigned int);
	m = 2147483648;
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
