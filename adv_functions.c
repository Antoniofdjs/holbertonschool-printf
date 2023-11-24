#include "main.h"
/**
 *write_b - function to handle binaries
 *@my_args: my va_list
 *Return: total count of characters
 */
int write_b(va_list *my_args)
{
unsigned int result, temp;
int i, digits = 0, count = 0;
char *str;

result = va_arg(*my_args, unsigned int);

temp = result;

while (temp != 0)
{
temp /= 2;
digits++;
}
str = malloc(sizeof(char) * (digits + 1));
if (str == NULL)
{
write(1, "(NILL)", 6);
return (6);
}
for (i = digits - 1; i >= 0; i--)
{
str[i] = '0' + (result % 2);
result /= 2;
}
for (i = 0; i < digits; i++)
{
write(1, &str[i], 1);
count++;
}
free(str);
return (count);
}
