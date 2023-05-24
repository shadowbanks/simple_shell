#include "main.h"

/**
 * _unsetenv - Remove an environment varaible if exist
 * @my_env: the environmental variable
 * @name: name of environment variable to remove
 * Return: 0 on success -1 on failure
 */

int _unsetenv(char **my_env, const char *name)
{
        int k = 0, l, check = 0;

        /*search for "name", replace it's value if overwrite != 0*/
        while (my_env[k])
        {
                if (_strncmp(my_env[k], name, _strlen(name)) == 0)
                {
                        if (my_env[k][_strlen(name)] == '=')
                        {
                                check = 1;
                                free(my_env[k]);
                                break;
                        }
                }
                k++;
        }

        if (check == 1)
        {
                l = k + 1;

                while (my_env[l])
                {
                        my_env[k] = my_env[l];
                        k++, l++;
                }
                my_env[k] = NULL;

                return (0);
        }
        return (-1);
}

/**
 * base_conv - base convertion from decimal to other base
 * @buffer: location to save the string
 * @num: number to be converted
 * @base: desired base
 *
 * Return: lenght of converted number (now in string)
 */
int base_conv(char *buffer, long num, int base)
{
        char *temp;
        int digit, sign = 0, len = 0;

        if (num == 0)
        {
                *buffer++ = 0 + '0';
                *buffer = '\0';
                return (_strlen(buffer));
        }
        temp = buffer;

        if (num < 0)
        {
                sign = 1;
                num = -num;
        }
        while (num)
        {
                digit = num % base;
                if (digit > 9)
                {
                        *temp++ = digit + 'a' - 10;
                        len++;
                }
                else
                        *temp++ = digit + '0';
                num /= base;
        }
        if (len == 1)
                *temp++ = 0 + '0';

        if (sign)
                *temp++ = '-';
        *temp = '\0';

        rev_string(buffer);

        return (_strlen(buffer));
}

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

/**
 * main - Shell program
 * @ac: argument counter
 * @av: argument variable
 * @env: environment variable
 *
 * Return: 0 (on success)
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)), char **env)
{
        int i = 0, status = 0, a = 1, j = 0;
        char *original_path, *pmt = "# ", status_str[10];

        char *my_env[100];

        while (env[j])
        {
                my_env[j] = malloc(_strlen(env[j]) * sizeof(char) + 1);
                if (my_env[j] == NULL)
                        return (-1);
                _strcpy(my_env[j], env[j]);
                j++;
        }
        my_env[j] = NULL;
        original_path = _getenv(my_env, "PATH");
        _setenv(my_env, "OLDPWD", "", 1);

        while (a)
        {
                base_conv(status_str, status, 10);
                _setenv(my_env, "?", status_str, 1);
                /*Is this fine????*/
                if (isatty(STDIN_FILENO))
                        write(1, pmt, 2);
                i = prompt(my_env, original_path, &status);
                if (i == 1)
                        continue;
                else if (i == 7)
                        a = 0;
                else
                        a = 0;
        }

        j = 0;
        while (my_env[j])
                free(my_env[j++]);
        write(1, "\n", 1);
        return (status);
}
