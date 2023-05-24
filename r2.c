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
        ssize_t rd, red = 0;

        *lineptr = malloc((sizeof(char) * BUFF));
        if (*lineptr == NULL)
                return (-1);

        while ((rd = read(fd, *lineptr + red, BUFF)) > 0)
        {
                *n = *n + BUFF;
                *lineptr = _realloc(*lineptr, *n, (*n + BUFF));
                if (*lineptr == NULL)
                {
                        free(*lineptr);
                        return (-1);
                }
                red = red + rd;
                if ((*lineptr)[red - 1] == '\n')
                        break;
        }
        if (rd < 0)
        {
                free(*lineptr);
                return (-1);
        }
        (*lineptr)[red] = '\0';
        return (red);
}

/**
 * _realloc - reallocates a momeory block using malloc and free
 * @ptr: pointer to old block of memory
 * @old_size: size of the old block of memory
 * @new_size: size of the new block of memory
 *
 * Return: pointer to memory block or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
        void *new = NULL;

        if (ptr != NULL)
        {
                if (new_size == old_size)
                        return (ptr);
                if (new_size == 0)
                {
                        free(ptr);
                        return (NULL);
                }
                else if (new_size > old_size)
                {
                        new = malloc(new_size);
                        if (new != NULL)
                        {
                                memcpy(new, ptr, old_size);
                                free(ptr);
                                return (new);
                        }
                }
        }
        ptr = malloc(new_size);
        if (ptr == NULL)
                return (NULL);
        return (ptr);
}

/**
 * _setenv - Set or replace an envrionment "namee=value"
 * @my_env: shell environment variable
 * @name: environment name
 * @value: environment value
 * @overwrite: 0 (don't change value) else change environment value
 *
 * Return: 0 (success), 1 (fail);
 */
int _setenv(char **my_env, const char *name, const char *value, int overwrite)
{
        int i = 0, j = 0;
        char *new_env = NULL;

        new_env = malloc(_strlen(name) + _strlen(value) + 2);
        if (!new_env)
                return (1);

        while (name[i])
        {
                new_env[i] = name[i];
                i++;
        }
        new_env[i++] = '=';
        while (value[j])
        {
                new_env[i] = value[j];
                i++, j++;
        }

        if (check_env(my_env, new_env, overwrite, name) == 1)
        {
                free(new_env);
                return (1);
        }
        return (0);
}

/**
 * check_env - check if an environment exist
 * or a new is needed
 * @my_env: environment variables
 * @new_env: new environment variable
 * @overwrite: 0 (value shouldn't change) else (change value)
 * @name: environment name
 *
 * Return: 0 (success), 1 (failure)
 */
int check_env(char **my_env, char *new_env, int overwrite, const char *name)
{
        int k = 0;
        char *temp = NULL;

        /*search for "name", replace it's value if overwrite != 0*/
        while (my_env[k])
        {
                if (_strncmp(my_env[k], name, _strlen(name)) == 0)
                {
                        if (my_env[k][_strlen(name)] == '=')
                        {
                                if (overwrite != 0)
                                {
                                        temp = my_env[k];
                                        my_env[k] = new_env;
                                        free(temp);
                                }
                                else
                                        return (1);
                                break;
                        }
                }
                k++;
        }
        if (my_env[k] == NULL)
        {
                my_env[k++] = new_env;
                my_env[k] = NULL;
        }
        return (0);
}
