#include "main.h"
/**
* _printf - print variables to the standard output
*@format: The character string
*@...: number of variables to be printed to the standard output.
*Return: the number of characters printed
*(excluding the null byte used to end output to strings)
*/
int _printf(const char *format, ...)
{
int characters_print = 0;
va_list args;
if (format == NULL)
return (-1);
va_start(args, format);
while (*format)
{
if (*format != '%')
{
format++;
if (*format == '\0')
break;
else if (*format == '%')
characters_print += write(1, format, 1);
else if (*format == 'c')
{
char c = va_arg(args, int);
characters_print += write(1, &c, 1);
}
else if (*format == 's')
{
char *str = va_arg(args, char*);
int i = 0; while (str[i] != '\0')
{
characters_print += write(1, &str[i], 1);
i++;
}
}
else
{
va_end(args);
return (-1);
}
}
else
characters_print += write(1, format, 1);
format++;
}
va_end(args);
return (characters_print);
}
