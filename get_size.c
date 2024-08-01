#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;
    /*Check if the next character in the format string is 'l' (long) or 'h' (short*/
	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;
    /*Check if the next character in the format string is 'l' (long) or 'h' (short*/
	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
