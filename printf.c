#include "main.h"

/**
 * _printf - prints string and variables passed with format specifiers.
 * @format: the format specifier of the variable to be printed
 * Return: length of the output
 */
int _printf(const char *format, ...)
{
	int i, output_len = 0;
	va_list argPtr;
	flag f = {0, 0, 0};
	int (*spec_func)(va_list, flag *);

	va_start(argPtr, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			f.plus = f.space = f.hash = 0;
			spec_func = get_sf(format, &i, &f);
			if (spec_func)
				output_len += spec_func(argPtr, &f);
			else
			{
				_putchar('%');
				_putchar(format[i]);
				output_len += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			output_len++;
		}
	}
	_putchar(-1);
	va_end(argPtr);
	return (output_len);
}
