#include "main.h"

/**
 * rev_string -  prints a string, in reverse, followed by a new line
 * @s: pointer to a string
 * Return: void
 */
void rev_string(char *str)
{
	int len = 0, i, j = 0;
	char ch;

	len = _strlen(str);

	for (i = 0, j = len - 1; i < j; i++, j--)
	{
		ch = str[i];
		str[i] = str[j];
		str[j] = ch;
	}
}
