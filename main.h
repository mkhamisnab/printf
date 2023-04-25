#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>
#include <stdarg.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024
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
 * print_arg - This function handles the formatting of a single argument.
 * @specifier: The format specifier character (e.g. 'c', 's', '%', 'b').
 * @args: The va_list of arguments to format.
 * @buffer: The buffer to write the formatted output to.
 * @buf_index: A pointer to the current index in the buffer.
 * Return: None
 */
void print_arg(char specifier, va_list args, char *buffer, int *buf_index);

/**
 * struct format - Struct
 *
 * @specifier: conversion specifier.
 * @print_func: The associated function.
 */
struct format
{
    char specifier;
    void (*print_func)(va_list args, char *buffer, int *buf_index);
};

/**
 * fmt_t - Typedef for format
 */
typedef struct format fmt_t;
extern fmt_t fmt_types[];

void print_char(va_list args, char *buffer, int *buf_index);
void print_string(va_list args, char *buffer, int *buf_index);
void print_S(va_list args, char *buffer, int *buf_index);
void print_reverse(va_list args, char *buffer, int *buf_index);
void print_rot13(va_list args, char *buffer, int *buf_index);

void print_percent(va_list args, char *buffer, int *buf_index);
void print_binary(va_list args, char *buffer, int *buf_index);
void print_address(va_list args, char *buffer, int *buf_index);

void print_int(va_list args, char *buffer, int *buf_index);
void print_unsigned_integer(unsigned int num, int base, char *buffer, int *buf_index);
void print_unsigned(va_list args, char *buffer, int *buf_index);

void print_octal(va_list args, char *buffer, int *buf_index);
void print_hex_lower(va_list args, char *buffer, int *buf_index);
void print_hex_upper(va_list args, char *buffer, int *buf_index);
void print_hexa(va_list args, char map_to[], char *buffer, char, int *buf_index);

#endif
