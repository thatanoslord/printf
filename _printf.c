#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int total_bytes = 0;
	va_list args;
	char *ptr, *start;
	params_t params = PARAMS_INIT;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = (char *)format; *ptr; ptr++)
	{
		init_params(&params, args);
		if (*ptr != '%')
		{
			total_bytes += _putchar(*ptr);
			continue;
		}
		start = ptr;
		ptr++;
		while (get_flag(ptr, &params)) /* while char at ptr is flag char */
		{
			ptr++; /* next char */
		}
		ptr = get_width(ptr, &params, args);
		ptr = get_precision(ptr, &params, args);
		if (get_modifier(ptr, &params))
			ptr++;
		if (!get_specifier(ptr))
			total_bytes += print_from_to(start, ptr,
				params.l_modifier || params.h_modifier ? ptr - 1 : 0);
		else
			total_bytes += get_print_func(ptr, args, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(args);
	return (total_bytes);
}

