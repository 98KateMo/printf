#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _rev - prints a string in reverse
 * @str: string
 * @args: string to be reversed
 * Return: int
 */
int _rev(char *str, va_list args)
{
	int x = 0, i = 0;
	char *c = va_arg(args, char *);

	if (c != NULL)
	{
		while (c[i] && c != NULL)
			i++;
		--i;
		for (; i >= 0; i--)
		{
			str[x++] = c[i];
		}
		str[x] = '\0';
	}
	return (x);
}
