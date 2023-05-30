#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/* 
* _rot13 - Converts and prints a string in rot13.
 * @n: character counter.
 * @args: argument to be processed.
 * Return: void
*/
int _rot13(va_list args)
{
        int i, j, characters = 0;
        char *c = va_arg(args, char *);
        char *a = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char *r = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

        for (i = 0; c[i] && c != NULL; i++)
        {
                for (j = 0; a[j]; j++)
                {
                        if (c[i] == a[j])
                        {
                                write(1, &r[j], 1);
                                ++characters;
                                break;
                        }
                        else
                        {
                                write(1, &c[i], 1);
                                ++characters;
                                break;
                        }
                }
        }
        return (characters);
}
