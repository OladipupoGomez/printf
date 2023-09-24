#include "main.h"
/**
*print_binary - print binary output to the standard output
*@num: number of variables to be printed to the standard output.
*@...: number of variables to be printed to the standard output.
*Return: 0 (success)
*/
void print_binary(unsigned int num)
{
int binary[32];
int index = 0;
while (num > 0)
{
binary[index++] = num % 2;
num /= 2;
}
if (index == 0)
{
write(1, "0", 1);
}
else
{
while (--index >= 0)
{
char digit = binary[index] + '0';
write(1, &digit, 1);
}
}
}
/**
*_printf - print variables to the standard output
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
else if (*format == '%')
count += write(1, format, 1);
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
else if (*format == 'd' || *format == 'i')
{
int num = va_arg(args, int);
char num_str[12];
int i = 0;
int is_negative = 0;
if (num < 0)
{
is_negative = 1;
num = -num;
}
do {
num_str[i++] = num % 10 + '0';
num /= 10;
}
while (num > 0);
{
write(1, &num_str, 1);
}
if (is_negative)
num_str[i++] = '-';
while (i > 0)
count += write(1, &num_str[--i], 1);
}
else if (*format == 'u')
{
unsigned int num = va_arg(args, unsigned int);
print_binary(num);
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
/**
*main - entry point
*
*Return: Always 0
*/
int main(void)
{
_printf("Decimal: %d\n", 42);
_printf("Binary: %u\n", 42);
return (0);
}
