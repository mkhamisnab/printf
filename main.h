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
int _strlen(const char *str);

/**
 * rev_string -  prints a string, in reverse, followed by a new line
 * @str: pointer to a string
 * Return: void
 */
void rev_string(char *str);

/**
 * cal_binary -  calculates binary of a number
 * @num: number
 * Return: binary
 */
char *cal_binary(unsigned int num);

/**
 * print_arg - This function handles the formatting of a single argument.
 * @specifier: The format specifier character (e.g. 'c', 's', '%', 'b').
 * @args: The va_list of arguments to format.
 * @buffer: The buffer to write the formatted output to.
 * @buf_index: A pointer to the current index in the buffer.
 * Return: None
 */
void print_arg(char specifier, va_list args, char *buffer, int *buf_index);

#endif
