#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * _binary - converts a number to binary
 * @args: number to be converted to binary
 * Return: int
 */
int _binary(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char binary[32];
	int j, characters = 0, i = 0;

	while (num > 0)
	{
		binary[i++] = (num % 2) + '0';
		num /= 2;
	}
	for (j = i - 1; j >= 0; j--)
	{
		write(1, &binary[j], 1);
		++characters;
	}
	return (characters);
}
