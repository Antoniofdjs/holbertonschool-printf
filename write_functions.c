#include <stdio.h>
#include "main.h"
#include "string.h"
#include <unistd.h>
#include "stdarg.h"
#include "stdlib.h"
#include <stdint.h>

/**
 * write_s - function for writing strings from a list
 * @my_args: my va_list
 * Return: total count of characters
 */

int write_s(va_list *my_args)
{
	char *current_str;
	int j = 0, count = 0;

	current_str = va_arg(*my_args, char *);
	if (current_str == NULL)
	{
		write(1, "(NILL)", 6);
		return (6);
	}
	while (current_str[j] != '\0')
	{
		write(1, &current_str[j], 1);
		j++, count++;
	}
	return (count);
}

/**
 * write_c - writes single chars from list
 * @my_args: my va_list
 * Return: total count of characters
 */

int write_c(va_list *my_args)
{
	char current_char;

	current_char = va_arg(*my_args, int);
	if (current_char == '\0')
	{
		write(1, "(NILL)", 6);
		return (6);
	}

	write(1, &current_char, 1);
	return (1);
}

/**
 * write_d - writes ints or decimal from list
 * @my_args: my va_list
 * Return: total count of characters
 */

int write_d(va_list *my_args)
{
	int temp, result, digits, count = 0, i;
	char *str;

	result = va_arg(*my_args, int);
	if (result < 0)
	{
		result = -result;
		write(1, "-", 1);
		count++;
	}
	temp = result;
	digits = 0;
	while (temp != 0)/*count the number of digits*/
	{
		temp /= 10;
		digits++;
	}
	str = malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (-1);
	if (str == NULL)
		exit(98);
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
	return (count + 2);
}

/**
 * write_p ->>>>>COMMENT HERE LOUIS<<<<
 * @my_args: my va_list
 * Return: total count of characters
 */

int write_p(va_list *my_args)
{
	void *ptr = va_arg(*my_args, void *);
	uintptr_t addr = (uintptr_t)ptr;
	uintptr_t temp;
	unsigned int count = 0;
	char *str;
	int digits = 0, i;

	if (addr == 0)
	{
		write(1, "(nil", 5);
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

	str[0] = '0';/* >>>>COMMENT HERE LOUIS<<<< */
	str[1] = 'x';
	for (i = digits + 1; i >= 2; i--)
	{
		if (addr % 16 > 9)
			str[i] = 'a' + (addr % 16 - 10);
		else
			str[i] = '0' + addr % 16;
	addr /= 16;
	}
	str[digits + 2] = '\0';/* >>> COMMENT HERE LOUIS<<< */
	for (i = 0; i < digits + 2; i++)
	{
		write(1, &str[i], 1);
		count++;
	}
	free(str);
	return (count);
}
