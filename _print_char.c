#include "main.h"

/**
 * _print_char - prints a character
 * @argPtr: argument pointer
 * @f: flag ptr
 * Return: 1 (success)
 */

int _print_char(va_list argPtr, flag *f)
{
	char c;

	(void)f;
	c = va_arg(argPtr, int);
	_putchar(c);
	return (1);
}
