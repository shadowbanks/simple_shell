#include "main.h"

/**
 * prompt - Display the shell prompt, read user input
 * set "$" to process ID, call get_token
 * @my_env: shell environment variable
 * @original_path: environment path
 * @status: hold the last return value
 *
 * Return: 1 (if user only hits enter i.e display prompt again)
 * 7 (if EOF), -1 (on failure)
 */
int prompt(char **my_env, char *original_path, int *status)
{
	ssize_t gline;
	size_t n = 0;
	char *lineptr = NULL, pid_str[10];
	pid_t my_pid;

	gline = _getline(&lineptr, &n, stdin);

	my_pid = getpid();
	base_conv(pid_str, my_pid, 10);
	_setenv(my_env, "$", pid_str, 1);

	if (gline == -1)
	{
		free(lineptr);
		return (-1);
	}
	else if (gline == 0)
	{
		free(lineptr);
		return (7);
	}
	if (gline == 1)/*Check if nothing was typed i.e press only enter key */
	{
		free(lineptr);
		return (1);
	}

	if (lineptr[gline - 1] == '\n')
		lineptr[gline - 1] = '\0';

	if (get_token(my_env, lineptr, original_path, status) == 99)
	{
		free(lineptr);
		return (-1);
	}

	free(lineptr);
	return (1);
}
