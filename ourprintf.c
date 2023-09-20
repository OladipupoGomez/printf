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
va_list list_of_args;

if (format == NULL)
{
return (-1);
}

va_start(list_of_args, format);

while (*format)
{
if (*format != '%')
{
write(1, format, 1);
characters_print++;
}
else
{
format++;
if (*format == '\0')
{
break;
}
else if (*format == '%')
{
write(1, format, 1);
characters_print++;
}
else if (*format == 'c')
{
char c = va_arg(list_of_args, int);
write(1, &c, 1);
characters_print++;
}
else if (*format == 's')
{
char *str = va_arg(list_of_args, char*);
int str_len = 0;
while (str[str_len] != '\0')
{
str_len++;
}
write(1, str, str_len);
characters_print += str_len;
}
}
format++;
}

va_end(list_of_args);
return (characters_print);
}
