#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _hex_upper - prints number in hex
 * @args: argument to be converted
 * Return: int
 */
int _hex_upper(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
char hex[17] = {0};
int remainder, i = 0;
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
write(1, &hex[i], 1);
++characters;
}
return (characters);
}
