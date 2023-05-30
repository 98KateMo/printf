#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _rev - prints a string in reverse
 * @args: string to be reversed
 * Return: int
 */
int _rev(va_list args)
{
	int i = 0, characters = 0;
	char *str = va_arg(args, char *);

	while (str[i] && str != NULL)
		i++;
	--i;
	for (; i >= 0; i--)
	{
		write(1, &str[i], 1);
		++characters;
	}
	return (characters);
}
