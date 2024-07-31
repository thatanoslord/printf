#include "main.h"
/**
 * _print_str - prints a string
 * @argPtr: argument pointer
 * @f: flag ptr
 * Return: string length
 */

int _print_str(va_list argPtr, flag *f)
{
	char *str;
	int len;

	(void)f;
	str = va_arg(argPtr, char *);

	if (!str)
	{
		str = "(null)";
		len = _strlen(str);
		_puts(str);
		return (len);
	}

	len = _strlen(str);
	_puts(str);
	return (len);
}
