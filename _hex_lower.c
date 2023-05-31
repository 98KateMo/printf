#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _hex_lower - prints number in hex
 * @str: string
 * @args: argument to be converted
 * Return: int
 */
int _hex_lower(char *str, va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	char hex[17] = {0};
	int remainder, j = 0, i = 0;
	int characters = 0;

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
