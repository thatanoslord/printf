#include "main.h"
/**
 * print_unsigned - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	/* Convert the number and handle base case */
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	/* Convert number to string and handle formatting */
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	/* Write the formatted number and return the count */
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	/* Convert the number and handle base case */
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	/* Convert number to octal string and handle formatting */
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	/* Add "0" prefix if the F_HASH flag is set */
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	/* Write the formatted octal number and return the count */
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Call the general hexa print function with lowercase hexa map */
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer to handle print
 * @flags: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	/* Call the general hexa print function with uppercase hexa map */
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lowercase or uppercase
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer to handle print
 * @flags: Active flags
 * @flag_ch: Active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	/* Convert the number and handle base case */
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	/* Convert number to hexadecimal string and handle formatting */
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	/* Add "0x" prefix if the F_HASH flag is set */
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	/* Write the formatted hexadecimal number and return the count */
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}