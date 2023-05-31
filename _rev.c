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
	int i = 0;
	str = va_arg(args, char *);

	while (str[i] && str != NULL)
		i++;
	--i;
	return (i);
}
