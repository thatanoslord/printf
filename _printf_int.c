#include "main.h"

/**
 * add_flag - adds a flag to the number
 * @f: pointer to flag struct
 * Return: 1(for add flag)
 */
int add_flag(flag *f)
{
	if (f->plus)
		return (_putchar('+'));
	else if (f->space)
		return (_putchar(' '));
	return (0);
}

/**
 * _print_int - Function to print integer
 * @argPtr: argument Pointer
 * @f: pointer to flag struct
 * Return: counter(number of printed characters)
 */
int _print_int(va_list argPtr, flag *f)
{
	int n = va_arg(argPtr, int), count = 0, i = 0;
	unsigned int num;
	char buffer[11]; /* INT_MAX has 10 digits, plus null terminator */

	if (n == 0)
	{
		count += add_flag(f);
		return (count + _putchar('0'));
	}

	if (n < 0)
	{
		count += _putchar('-');
		num = (unsigned int)(-n);
	}
	else
	{
		count += add_flag(f);
		num = (unsigned int)n;
	}

	/* Store digits in reverse order */
	while (num > 0)
	{
		buffer[i++] = num % 10 + '0';
		num /= 10;
	}

	while (i > 0)
	{
		count += _putchar(buffer[--i]);
	}

	return (count);
}
