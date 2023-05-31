#include <unistd.h>
#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

/**
 * _char - prints a character
 * @str: string
 * @args: argument
 * Return: int
 */
int _char(char *str, va_list args)
{
	char c = va_arg(args, int);

	str[0] = c;
	str[1] = '\0';
	return (1);
}
/**
 * _string - prints a string
 * @str: string
 * @args: argument
 * Return: int
 */
int _string(char *str, va_list args)
{
	int i, characters = 0;
	char *c = va_arg(args, char *);

	for (i = 0; c[i] && c != NULL; i++)
	{
		str[i] = c[i];
		++characters;
	}
	str[i] = '\0';
	return (characters);
}
