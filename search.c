#include "main.h"

/**
 * searchfile - Search for command alias
 * @av: array of commands to find
 * @path: envirnoment path
 *
 * Return: command's full path or NULL
 */
char *searchfile(char **av, char *path)
{
	struct stat stbuf;
	/*char *path = getenv("PATH");*/
	char *path_dir = NULL, *buff = NULL;
	int i = 0;

	path_dir = strtok(path, ":");

	while (path_dir)
	{
		i = 0;
		if (av[i][0] != '/' && av[i][0] != '.')
		{
			buff = malloc(_strlen(path_dir) + _strlen(av[i]) + 2);
			if (buff == NULL)
				return (NULL);
			_strcpy(buff, path_dir);
			_strcat(buff, "/");
			_strcat(buff, av[i]);
		}
		else
		{
			buff = malloc(_strlen(av[i]) + 1);
			if (buff == NULL)
				return (NULL);
			_strcpy(buff, av[i]);
		}

		if (stat(buff, &stbuf) == 0)
		{
			return (buff);
		}

		free(buff);
		path_dir = strtok(NULL, ":");
		i++;
	}
	return (NULL);
}
