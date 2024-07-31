#include "main.h"

/**
 * _print_STR - prints a string
 * @argPtr: argument pointer
 * @f: flag ptr
 * Return: string length
 */

int _print_STR(va_list argPtr, flag *f)
{
	char *str;
	int len = 0;

	(void)f;
	str = va_arg(argPtr, char *);
	if (!str)
	{
		str = "(null)";
		len = _strlen(str);
		_puts(str);
		return (len);
	}
	while (*str)
	{
		if (*str < 32 || *str >= 127)
		{
			len += _putchar('\\');
			len += _putchar('x');
			if (*str < 16)
			{
				len += _putchar('0');
				len += HEX(*str);
			}
			else
			{
				len += HEX(*str);
			}
		}
		else
		{
			len += _putchar(*str);
		}
		str++;
	}
	return (len);
}
