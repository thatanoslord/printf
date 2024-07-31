#include "main.h"
/**
 * hex - converts passed number to hexadecimal(lower case)
 * @n: number to convert to hex
 * Return: length of hexadecimal
 */

int hex(unsigned long int n)
{
	long int len = 0, i;
	long int *p;
	unsigned long int temp;

	if (n == 0)
		return (_putchar('0'));

	temp = n;
	while (temp > 0)
	{
		temp /= 16;
		len++;
	}

	p = malloc(sizeof(long int) * len);

	if (!p)
		return (-1);

	for (i = 0; i < len; i++)
	{
		p[i] = n % 16;
		n /= 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (p[i] > 9)
			p[i] += 39;
		_putchar(p[i] + '0');
	}
	free(p);
	return (len);
}

/**
 * HEX - converts passed number to hexadecimal(upper case)
 * @n: number to convert to hex
 * Return: length of hexadecimal
 */

int HEX(unsigned long int n)
{
	long int len = 0, i;
	long int *p;
	unsigned long int temp;

	if (n == 0)
		return (_putchar('0'));

	temp = n;
	while (temp > 0)
	{
		temp /= 16;
		len++;
	}

	p = malloc(sizeof(long int) * len);
	if (!p)
		return (-1);

	for (i = 0; i < len; i++)
	{
		p[i] = n % 16;
		n /= 16;
	}
	for (i = len - 1; i >= 0; i--)
	{
		if (p[i] > 9)
			p[i] += 7;
		_putchar(p[i] + '0');
	}
	free(p);
	return (len);
}
