#include "main.h"

/**
 * get_sf - Gets the appropriate function for a specifier
 * @format: The format string
 * @i: Pointer to the current position in the format string
 * @f: Pointer to the flag structure
 * Return: Pointer to the appropriate function, or NULL if not found
 */
int (*get_sf(const char *format, int *i, flag * f))(va_list, flag *)
{
	int j, convert_len = 13;
	fs convert[] = {
			{"%s", _print_str},
			{"%%", _print_percent},
			{"%c", _print_char},
			{"%d", _print_int},
			{"%i", _print_int},
			{"%b", _print_bin},
			{"%X", _print_HEX},
			{"%x", _print_hex},
			{"%p", _print_ptr},
			{"%o", _print_oct},
			{"%u", _print_unsigned},
			{"%S", _print_STR},
			{"%R", _print_rot13}
			};

	while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '#')
	{
		if (format[*i] == '+')
			f->plus = 1;
		else if (format[*i] == ' ')
			f->space = 1;
		else if (format[*i] == '#')
			f->hash = 1;
		(*i)++;
	}

	for (j = 0; j < convert_len; j++)
	{
		if (convert[j].specifier[1] == format[*i])
		{
			return (convert[j].conversion_func);
		}
	}

	return (NULL);
}
