#include "main.h"

/**
 * rev_string - Reverse a string
 * @s: the string
 *
 * Return: Nothing
 */
void rev_string(char *s)
{
	int len = _strlen(s) - 1;
	char temp;
	int i = 0;

	while (i < len)
	{
		temp = *(s + len);
		*(s + len) = *(s + i);
		*(s + i) = temp;
		i++, len--;
	}
}
