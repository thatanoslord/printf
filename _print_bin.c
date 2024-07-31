#include "main.h"
/**
 * _print_bin - prints binary number
 * @argPtr: argument pointer
 * @f: flag ptr
 * Return: number of digits of binary number
 */

int _print_bin(va_list argPtr, flag *f)
{
	unsigned int temp, num;
	int len = 0, i, bin, counter;
	char *p;

	(void)f;
	num = va_arg(argPtr, unsigned int);
	if (num == 0)
		return (_putchar('0'));
	temp = num;

	while (temp > 0)
	{
		temp /= 2;
		len++;
	}

	p = malloc(sizeof(char) * len);

	if (!p)
		return (-1);

	i = len;
	p[i--] = '\0';
	while (num > 0)
	{
		bin = num % 2;
		p[i--] = bin + '0';
		num /= 2;
	}

	counter = _puts(p);
	free(p);
	return (counter);
}
