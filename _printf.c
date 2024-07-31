#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: the format specifier of the variable to be printed
 * Return: length of the output
 */
int _printf(const char *format, ...)
{
	int index, total_length = 0;
	va_list args;
	flag flags = {0, 0, 0};
	int (*conversion_func)(va_list, flag *);

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (index = 0; format[index] != '\0'; index++)
	{
		if (format[index] == '%')
		{
			index++;
			flags.plus = flags.space = flags.hash = 0;
			conversion_func = get_sf(format, &index, &flags);
			if (conversion_func)
				total_length += conversion_func(args, &flags);
			else
			{
				_putchar('%');
				_putchar(format[index]);
				total_length += 2;
			}
		}
		else
		{
			_putchar(format[index]);
			total_length++;
		}
	}
	_putchar(-1);
	va_end(args);
	return (total_length);
}

