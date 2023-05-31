#include <unistd.h>
#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _unsigned_dec - prints an unsigned decimal
 * @str: string
 * @args: argument
 * Return: int
 */
int  _unsigned_dec(char *str, va_list args)
{
        unsigned int val, x, num, mul, tens = 1;
        int j = 0, characters = 0;
        unsigned int i = va_arg(args, unsigned int);
        char digit[2];

        for (val = i; val / 10 >= 1; val /= 10)
                ++tens;
        x = tens;
        mul = 1;
        for (val = i; val / 10 >= 1; val /= 10)
        {
                for (; x > 1; --x)
                        mul *= 10;
                digit[0] = (i / mul) + '0';
                digit[1] = '\0';
                num = (i / mul) * mul;
                mul /= 10;
                i -= num;
                str[j++] = digit[0];
                ++characters;
        }
        digit[0] = (i % 10) + '0';
        str[j] = digit[0];
	str[++j] = '\0';
        ++characters;
        return (characters);
}

/**
 * _octal - prints an octal number
 * @str: string
 * @args: argument
 * Return: int
 */
int _octal(char *str, va_list args)
{
        int x, s = 0, j = 0, characters = 0;
        unsigned int i = va_arg(args, unsigned int);
        char digit[BUFFER_SIZE];

        if (i == 0)
        {
                str[s] = '0';
                return (1);
        }
        while (i != 0)
        {
                x = i % 8;
                digit[j++] = x + '0';
                i /= 8;
        }
        for (i = j - 1; i > 0; i--)
        {
                str[s++] = digit[i];
                ++characters;
        }
        str[s] = digit[i];
	str[++s] = '\0';
        ++characters;
        return (characters);
}
