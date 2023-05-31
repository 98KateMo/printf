#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <stddef.h>
#include <stdarg.h>
int _char(char *str, va_list args);
int _string(char *str, va_list args);
int _signed_dec(char *str, va_list args);
int _unsigned_dec(char *str, va_list args);
int _octal(char *str, va_list args);
int _hex_upper(char *str,va_list args);
int _hex_lower(char *str, va_list args);
int _rev(char *str, va_list args);
int _rot13(char *str, va_list args);
int _address(char *str, va_list args);
int _binary(char *str, va_list args);
int process_format(const char *format, va_list args);
int process_specifier(char specifier, int flags, int width, int precision, va_list args);
int _printf(const char *format, ...);
#endif
