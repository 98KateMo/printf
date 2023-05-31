#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _rot13 - prints a string in rot13
 * @str: string
 * @args: argument
 * Return: int
 */
int _rot13(char *str, va_list args)
{
        int i, j, x = 0, characters = 0;
        char *c = va_arg(args, char *);
        char *a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char *r = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	if (c != NULL)
	{
        for (i = 0; c[i] && c != NULL; i++)
        {
                for (j = 0; a[j]; j++)
                {
                        if (c[i] == a[j])
                        {
                                str[x++] = r[j];
                                ++characters;
                                break;
                        }
                        else
                        {
                                str[x++] = c[i];
                                ++characters;
                                break;
                        }
                }
        }
	str[x] = '\0';
	}
        return (characters);
}
