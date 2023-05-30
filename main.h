#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <stddef.h>
#include <stdarg.h>
int _char(va_list args);
int _string(va_list args);
int _signed_dec(va_list args);
int _unsigned_dec(va_list args);
int _octal(va_list args);
int _hex_upper(va_list args);
int _hex_lower(va_list args);
int _rev(va_list args);
int _rot13(va_list args);
int _address(va_list args);
int _binary(va_list args);
int process_format(const char *format, va_list args);
int process_specifier(char specifier, int flags, int width, va_list args);
int _printf(const char *format, ...);
#endif
