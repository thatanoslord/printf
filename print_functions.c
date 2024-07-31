#include "main.h"

/**
 * print_char - prints character
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_char(va_list args, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, total_bytes = 0, ch = va_arg(args, int);

	if (params->minus_flag)
		total_bytes += _putchar(ch);
	while (pad++ < params->width)
		total_bytes += _putchar(pad_char);
	if (!params->minus_flag)
		total_bytes += _putchar(ch);
	return (total_bytes);
}

/**
 * print_int - prints integer
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: number chars printed
 */
int print_int(va_list

