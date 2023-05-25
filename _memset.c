#include "main.h"

/**
 * _memset -  Fill "n" bytes of the memory area pointed
 *  to by "s" with the constant byte b
 *  @s: Memory area to be filled
 *  @b: constant byte to be filled with
 *  @n: byte to be filled
 *
 *  Return: Pointer to the memory area "s"
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}

	return (s);
}
