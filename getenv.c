#include "main.h"

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
