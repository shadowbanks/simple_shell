#include "main.h"


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
