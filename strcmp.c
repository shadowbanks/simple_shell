#include "main.h"

/**
 * _strncmp - Compare (n)bytes of two strings
 * @s1: first string
 * @s2: second string
 * @n: bytes to be compared
 *
 * Return: the integer difference
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);

		if (s1[i] == '\0')
			break;
		i++;
	}

	return (0);
}
