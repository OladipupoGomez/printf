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
va_list args;
int count = 0;
if (!format)
return (-1);
va_start(args, format);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')
break;
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
int neg = (num < 0) ? 1 : 0;
char num_str[12];
int i = 0;
if (neg)
num = -num;
do {
num_str[i++] = num % 10 + '0';
num /= 10;
} while (num > 0);
if (neg)
num_str[i++] = '-';
while (i > 0)
count += write(1, &num_str[--i], 1);
}
else if (*format == 'c')
{
char c = va_arg(args, int);
count += write(1, &c, 1);
}
else if (*format == 's')
{
char *str = va_arg(args, char*);
while (*str)
count += write(1, str++, 1);
}
else
{
count += write(1, format - 1, 2);
}
}
else
{
count += write(1, format, 1);
}
format++;
}
va_end(args);
return (count);
}
