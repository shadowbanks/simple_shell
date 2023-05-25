#include "main.h"

/**
 * _getline - my getline function
 * @lineptr: pointer to pointer where what is read
 * should be stored or NULL
 * @n: byte size or 0
 * @stream: where input should be read from
 *
 * Return: bytes read
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int fd = fileno(stream);
	ssize_t rd;
	size_t red = 0;
	char ch;

	*lineptr = malloc((sizeof(char) * BUFF));
	if (*lineptr == NULL)
		return (-1);

	while ((rd = read(fd, &ch, 1)) > 0)
	{
		if (ch == '\n')
		{
			(*lineptr)[red++] = ch;
			break;
		}
		(*lineptr)[red++] = ch;

		if (red == *n + 1)
		{
			*n = *n + BUFF;
			*lineptr = _realloc(*lineptr, *n, (*n + BUFF));
			if (*lineptr == NULL)
			{
				free(*lineptr);
				return (-1);
			}
		}
	}

	if (rd < 0)
	{
		free(*lineptr);
		return (-1);
	}
	(*lineptr)[red] = '\0';

	if (rd == 0)
		return (0);
	return (red);
}
