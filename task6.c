#include <unistd.h>
#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _address - prints a memory address
 * @str: string
 * @args: arguments
 * Return: int
 */
int _address(char *str, va_list args)
{
        void *address = va_arg(args, void *);
        intptr_t num = (intptr_t)address;
        char hex[17] = {0};
        int remainder, j = 0, i = 0;
        int characters = 0;

        str[j++] = '0';
	str[j++] = 'x';
        characters = 2;

        while (num != 0)
        {
                remainder = num % 16;
                hex[i++] = (remainder < 10) ? remainder + '0' :
                        remainder - 10 + 'a';
                num /= 16;
        }
        for (i = i - 1; i >= 0; i--)
        {
                str[j++] = hex[i];
                ++characters;
        }
	str[j] = '\0';
        return (characters);
}
