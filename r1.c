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
        int i;

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
                        buff = malloc(_strlen(av[i]));
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
        }
        return (NULL);
}

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
        size_t i = 0, s1Len = _strlen(s1), s2Len = _strlen(s2);

        while (i < s1Len && i < s2Len && i < n)
        {
                if (s1[i] != s2[i])
                        return (s1[i] - s2[i]);
                i++;
        }

        return (0);
}

/**
 * _strcmp - Compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: the integer difference
 */
int _strcmp(const char *s1, const char *s2)
{
        int i = 0;
        int s1Len = _strlen(s1);
        int s2Len = _strlen(s2);

        while (i < s1Len && i < s2Len)
        {
                if (s1[i] != s2[i])
                        return (s1[i] - s2[i]);
                i++;
        }

        return (s1[i] - s2[i]);
}

/**
 * _getenv - Get the value of an environment name
 * @my_env: shell's environment variables
 * @name: environment name
 *
 * Return: the environment value
 */
char *_getenv(char **my_env, const char *name)
{
        int k = 0;

        while (my_env[k])
        {
                if (_strncmp(my_env[k], name, _strlen(name)) == 0)
                {
                        if (my_env[k][_strlen(name)] == '=')
                                return (my_env[k] + _strlen(name) + 1);
                }
                k++;
        }
        return (NULL);
}
