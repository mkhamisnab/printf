#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>

/**
 * _printf - This function prints a formatted string to the standard output.
 * @format: A string containing zero or more format specifiers.
 * Return: the number of characters printed
 */
int _printf(const char *format, ...);

/**
 * _strlen - determine the length of a string
 * @str: string
 * Return: number of characters in the string
 */
size_t _strlen(const char *str);

#endif
