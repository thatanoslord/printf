#include "main.h"
/**
 * _strlen - returns length of a string
 * @s: string
 * Return: length of string
 */
int _strlen(char *s)
{
	int count;

	for (count = 0; s[count]; count++)
		;
	return (count++);
}
