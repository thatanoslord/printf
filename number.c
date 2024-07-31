#include "main.h"

/**
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: paramater struct
 *
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *digits;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	digits = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = digits[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * print_unsigned - prints unsigned integer numbers
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_unsigned(va_list args, params_t *params)
{
	unsigned long num;

	if (params->l_modifier)
		num = (unsigned long)va_arg(args, unsigned long);
	else if (params->h_modifier)
		num = (unsigned short int)va_arg(args, unsigned int);
	else
		num = (unsigned int)va_arg(args, unsigned int);
	params->unsign = 1;
	return (print_number(convert(num, 10, CONVERT_UNSIGNED, params), params));
}

/**
 * print_address - prints address
 * @args: argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 */
int print_address(va_list args, params_t *params)
{
	unsigned long int addr = va_arg(args, unsigned long int);
	char *str;

	if (!addr)
		return (_puts("(nil)"));

	str = convert(addr, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (print_number(str, params));
}

