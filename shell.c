#include "main.h"

/**
 * main - Shell program
 * @ac: argument counter
 * @av: argument variable
 * @env: environment variables
 *
 * Return: 0 (on success)
 */
int main(int ac, char **av, char **env)
{
	int i = 0, status;
	char *lineptr = NULL, *pmt = "# ", *argv[] = {"", NULL};
	size_t n = 0;
	ssize_t gline;
	pid_t cpid;

	while (gline != EOF)
	{
		write(1, pmt, 2);
		gline = getline(&lineptr, &n, stdin);

		if (gline == -1)
			exit(1);
		if (gline == 1)/*Check if nothing was typed i.e press only enter key */
			continue;

		if (lineptr[gline - 1] == '\n')
		{
			lineptr[gline - 1] = '\0';
		}

		cpid = fork(); /*startt a child process*/
		if (cpid == -1) /*startt a child process*/
			perror("Error:");

		if (cpid == 0)
		{
			argv[0] = lineptr;/*assign the command read by getline*/

			if (execve(argv[0], argv, env) == -1)
			{
				perror("Error");
				exit(1);
			}
		}
		else
			wait(&status);/*wait for child process to end*/
	}
	free(lineptr);
	return (0);
}
