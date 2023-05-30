#include "main.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * _printf - A function that produces output according to a format
 * @format: specifies the format of the output
 * Return: returns the number of characters printed
 */
int _printf(const char *format, ...)
{
	int counter = 0;
	va_list args;

	va_start(args, format);
	counter = process_format(format, args);
	va_end(args);
	return counter;
}

/**
 * process_format - Processes the format string and performs the necessary
 * conversions
 * @format: specifies the format of the output
 * @args: va_list containing the arguments
 * Return: returns the number of characters printed
 */
int process_format(const char *format, va_list args)
{
	int flags, width, i, counter = 0;

	for (flags = width = i = counter = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			for (; format[i] == '-' || format[i] == '0'; i++)
			{
				if (format[i] == '-')
					flags |= 1;
				else if (format[i] == '0')
					flags |= 2;
			}
			if (format[i] >= '1' && format[i] <= '9')
			{
				width = 0;
				for (; format[i] >= '0' && format[i] <= '9'; i++)
				width = width * 10 + (format[i] - '0');
			}
			if (format[i + 1] == '%')
			{
				i++;
				write(1, &format[i], 1);
				counter++;
			}
			else
			{
				i++;
				counter += process_specifier(format[i],
							     flags, width, args);
			}
		}
		else
		{
			write(1, &format[i], 1);
			counter++;
		}
	}
	return counter;
}

/**
 * process_specifier - Processes the specifier character and perform the
 * necessary conversion
 * @specifier: the specifier character
 * @flags: format flags
 * @width: width specified in the format
 * @args: va_list containing the arguments
 * Return: returns the number of characters printed for the specifier
 */
int process_specifier(char specifier, int flags, int width, va_list args)
{
	int (*conversion_func[])(va_list) =
		{_char, _string, _signed_dec, _signed_dec, _unsigned_dec,
		 _octal, _hex_upper, _hex_lower, _rev, _rot13, _address, _binary};
	char specifiers[] = {'c', 's', 'd', 'i', 'u', 'o', 'X', 'x', 'r', 'R',
			     'p', 'b', '\0'};
	int i, counter = 0;
	int characters = 0;

	for (i = 0; specifiers[i] != '\0'; i++)
	{
		if (specifier == specifiers[i])
		{
			counter += conversion_func[i](args);
			break;
		}
	}
	if (flags > 0 && width > 0)
	{
		if (width - counter > 0)
		{
			characters = width - counter;
			for (i = 0; flags == 1 && i < characters; i++)
				write(1, " ", 1);
			for (i = 0; flags == 2 && i < characters; i++)
				write(1, "0", 1);
		}
	}
	counter += characters;
	return (counter);
}
