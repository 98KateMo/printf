#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <stddef.h>
#include <stdarg.h>
int _char(va_list);
int _string(va_list);
int _signed_dec(va_list);
int _unsigned_dec(va_list);
int _octal(va_list);
int _hex_upper(va_list);
int _hex_lower(va_list);
int _rev(va_list);
int _rot13(va_list);
int _address(va_list);
int process_format(const char *format, va_list args);
int process_specifier(char specifier, int flags, int width, va_list args);
int _printf(const char *format, ...);
#endif
