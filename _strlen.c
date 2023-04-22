#include <stddef.h>

/**
 * _strlen - determine the length of a string
 * @str: string
 * Return: number of characters in the string
 */
size_t _strlen(const char *str)
{
	int world_length, i;

	while (str != NULL && str[i] != '\n')
	{
		world_length++;
		i++;
	}
	return (world_length);
}
