#include "main.h"
/**
 * _print_HEX - converts passed number to hexadecimal
 * @argPtr: argument pointer
 * @f: flag pointer
 * Return: length of hexadecimal
 */

int _print_HEX(va_list argPtr, flag *f)
{
	unsigned int n = va_arg(argPtr, unsigned int);
	int len = 0, i, flag_len = 0;
	unsigned int temp = n;
	char buffer[8];

	if (n == 0)
		return (_putchar('0'));

	if (f->hash && n != 0)
	{
		_putchar('0');
		_putchar('X');
		flag_len += 2;
	}

	while (temp > 0)
	{
		unsigned int digit = temp % 16;

		buffer[len] = (digit < 10) ? (digit + '0') : (digit - 10 + 'A');
		temp /= 16;
		len++;
	}

	for (i = len - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}

	return (len + flag_len);
}
