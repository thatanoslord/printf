#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */
int _printf(const char *format, ...)
{
	int total_chars = 0;
	va_list arg_list;
	char *current_char, *format_start;
	params_t params = PARAMS_INIT;

	va_start(arg_list, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (current_char = (char *)format; *current_char; current_char++)
	{
		init_params(&params, arg_list);
		if (*current_char != '%')
		{
			total_chars += _putchar(*current_char);
			continue;
		}
		format_start = current_char;
		current_char++;
		while (get_flag(current_char, &params)) /* while char at current_char is flag char */
		{
			current_char++; /* next char */
		}
		current_char = get_width(current_char, &params, arg_list);
		current_char = get_precision(current_char, &params, arg_list);
		if (get_modifier(current_char, &params))
			current_char++;
		if (!get_specifier(current_char))
			total_chars += print_from_to(format_start, current_char,
				params.l_modifier || params.h_modifier ? current_char - 1 : 0);
		else
			total_chars += get_print_func(current_char, arg_list, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(arg_list);
	return (total_chars);
}

