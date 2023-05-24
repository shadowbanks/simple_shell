#include "main.h"

/**
 * _strlen -Get the length of a string
 * @s: the string
 *
 * Return: length of string
 */
size_t _strlen(const char *s)
{
	size_t i = 0;

	while (*s != '\0')
		i++, s++;
	return (i);
}
