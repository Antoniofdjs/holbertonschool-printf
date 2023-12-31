#include "main.h"
#include <limits.h>

/**
 * write_d - convert integers to chars from va list
 * @my_args: my va_list
 * Return: total count of characters
 */

int write_d(va_list *my_args)
{
	int temp, result = va_arg(*my_args, int), digits = 0, count = 0, i;
	char *str;

	if (result == '\0')
	{
		write(1, "0", 1);
		return (1);
	}
	if (result == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (result < 0)
	{
		result = -result;
		write(1, "-", 1);
		count++;
	}
	temp = result;
	while (temp != 0)/*count the number of digits*/
	{
		temp /= 10;
		digits++;
	}
	str = malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (-1);
	for (i = digits - 1; i >= 0; i--)/* storing nums in str in reverse */
	{
		str[i] = '0' + (result % 10);
		result /= 10;
	}
	for (i = 0; i < digits; i++)
	{
		write(1, &str[i], 1);
		count++;
	}
	free(str);
	return (count);
}

/**
 * write_x - convert decimals to hex & writes them from va_list
 * @my_args: my va_list
 * @format: char from my_printf,contains x or X
 * Return: total count of characters
 */

int write_x(va_list *my_args, const char *format)
{
	unsigned int result = 0, count = 0;
	char *str;
	int digits = 0, temp, i, is_low = 0;

	if (*format == 'x')
		is_low = 32;/*variable changes to lower cases if needed */
	result = va_arg(*my_args, int);
	if (result == '\0')
	{
		write(1, "0", 1);
		return (1);
	}
	temp = result;
	while (temp != 0)/*count the number of digits*/
	{
		temp /= 16;
		digits++;
	}
	str = malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		exit(98);
	for (i = digits - 1; i >= 0; i--)/* storing nums in str in reverse */
	{
		if ((result % 16 > 9))/* 10 - 16 cases */
			str[i] = 'A' + is_low + ((result % 16) - 10);/* example 11 = a + 1 = b */
		else
			str[i] = ('0' + result % 16); /* 0 - 9 cases */
		result /= 16;
	}
	for (i = 0; i < digits; i++)
	{
		write(1, &str[i], 1);
		count++;
	}
	free(str);
	return (count);
}

/**
 * write_u - writes usigned ints from va_list
 * @my_args: my va_list
 * Return: total count of characters
 */

int write_u(va_list *my_args)
{
	unsigned int temp, result, digits, i;
	char *str;
	int count;

	result = va_arg(*my_args, int);

	temp = result;
	digits = 0;
	while (temp != 0)/*count the number of digits*/
	{
		temp /= 10;
		digits++;
	}
	str = malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
	{
		write(1, "(NILL)", 6);
		return (6);
	}
	for (i = digits - 1; i <= digits; i--)/* storing nums in str in reverse */
	{
		str[i] = '0' + (result % 10);
		result /= 10;
	}
	for (i = 0; i < digits; i++)
	{
		write(1, &str[i], 1);
		count++;
	}
	free(str);
	return (count);
}

/**
 *write_o - convert decimals to octal & write them from va_list
 *@my_args: my va_list
 *Return: total count of characters
 */

int write_o(va_list *my_args)
{
	unsigned int count = 0, result = 0;
	char *str;
	int digits, temp, i;

	result = va_arg(*my_args, int);

	temp = result;
	digits = 0;

	while (temp != 0)/*Calculate the number of digits in the octal*/
	{
		temp /= 8;
		digits++;
	}
	str = malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
	{
		exit(98);/*Exit if memory allocation fails*/
	}
	for (i = digits - 1; i >= 0; i--) /* Storing remainders in string */
	{
		str[i] = '0' + (result % 8); /*Convert remainders to characters*/
		result /= 8;
	}
	for (i = 0; i < digits; i++)
	{
		write(1, &str[i], 1);
		count++;
	}
	free(str);
	return (count);
}

/**
 * write_p - Write a pointer address in hexadecimal format.
 * @my_args: my va_list
 * Return: total count of characters
 */

int write_p(va_list *my_args)
{
	void *ptr = va_arg(*my_args, void *);
	uintptr_t addr = (uintptr_t)ptr;/* Convert *ptr to uintptr_t for */
	uintptr_t temp;
	unsigned int count = 0;
	char *str;
	int digits = 0, i;

	if (addr == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	temp = addr;
	while (temp != 0)/*calculate the number of digits*/
	{
		temp /= 16;
		digits++;
	}
	str = malloc(sizeof(char) * (digits + 3));
	if (str == NULL)
		exit(98);

	str[0] = '0';/*the first character as '0'*/
	str[1] = 'x';/*the second characters as '0'*/
	for (i = digits + 1; i >= 2; i--)
	{
		if (addr % 16 > 9)
			str[i] = 'a' + (addr % 16 - 10);
		else
			str[i] = '0' + addr % 16;
		addr /= 16;
	}
	str[digits + 2] = '\0';/*null terminator at the end of the string*/
	for (i = 0; i < digits + 2; i++)
	{
		write(1, &str[i], 1);
		count++;
	}
	free(str);
	return (count + 2);
}
