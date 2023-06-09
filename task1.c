#include <unistd.h>
#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _signed_dec - prints a signed decimal
 * @str: string
 * @args: argument
 * Return: int
 */
int _signed_dec(char *str, va_list args)
{
	int val, x, num, mul, tens = 1;
	int s = 0, characters = 0;
	int i = va_arg(args, int);
	char digit[2];

	if (i < 0)
	{
		write(1, "-", 1);
		i = -(i);
		++characters;
	}
	for (val = i; val / 10 >= 1; val /= 10)
		++tens;
	x = tens;
	mul = 1;
	for (val = i; val / 10 >= 1; val /= 10)
	{
		while (x > 1)
		{
			mul *= 10;
			--x;
		}
		digit[0] = (i / mul) + '0';
		digit[1] = '\0';
		num = (i / mul) * mul;
		mul /= 10;
		i -= num;
		str[s++] = digit[0];
		++characters;
	}
	digit[0] = (i % 10) + '0';
	str[s] = digit[0];
	str[++s] = '\0';
	++characters;
	return (characters);
}
