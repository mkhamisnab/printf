#include "main.h"
#include <stdlib.h>

/**
 * cal_binary -  calculates binary of a number
 * @num: number
 * Return: binary
 */

char *cal_binary(unsigned int num)
{
	char *binary;
	int reminder, i = 0;

	binary = (char *)malloc(20);
	if (binary == NULL)
		return (NULL);
	if (num == 0)
		binary[i] = '0';
	while (num != 0)
	{
		reminder = num % 2;
		binary[i++] = (char)(reminder + '0');
		num = num / 2;
	}
	binary[i++] = '\0';
	rev_string(binary);

	return (binary);
}
