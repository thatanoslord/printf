#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 1024

/**
 * struct flags - struct containing flags to activate
 * @plus: flag for +
 * @space: flag for ' '
 * @hash: struct for
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flag;

/**
 * struct format_specifier - defines a format specifier along
 * with its corresponding conversion function
 * @specifier: specifier string
 * @conversion_func: function that converts the specifier
 */

typedef struct format_specifier
{
	char *specifier;
	int (*conversion_func)(va_list, flag *);
} fs;

int _putchar(char);
int _puts(char *);
int hex(unsigned long int);
int HEX(unsigned long int);
char *rot13(char *s);
int _strlen(char *);
int _print_str(va_list argPtr, flag *);
int _print_percent(va_list, flag *);
int _print_char(va_list argPtr, flag *);
int _print_int(va_list argPtr, flag *);
int _print_bin(va_list argPtr, flag *);
int _print_hex(va_list argPtr, flag *);
int _print_HEX(va_list argPtr, flag *);
int _print_ptr(va_list argPtr, flag *);
int _print_oct(va_list argPtr, flag *);
int _print_unsigned(va_list argPtr, flag *);
int _print_STR(va_list argPtr, flag *f);
int _print_rot13(va_list argPtr, flag *);
int (*get_sf(const char *format, int *i, flag *f))(va_list, flag *);
int _printf(const char *format, ...);

#endif
