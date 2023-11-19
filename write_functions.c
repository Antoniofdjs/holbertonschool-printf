#include <stdio.h>
#include "main.h"
#include "string.h"
#include <unistd.h>
#include "stdarg.h"
#include "stdlib.h"

int write_s(va_list *my_args)
{

	char *current_str;
	int j = 0;
	int count = 0;

	current_str = va_arg(*my_args, char *);
	if (current_str == NULL)
	{
		write(1,"(NILL)", 6);
		return (0);
	}
	while (current_str[j] != '\0')
	{
		write(1, &current_str[j], 1);
		j++;
		count++;
	}

	return (count);
}

int write_c(va_list *my_args)
{
	char current_char;
	current_char = va_arg(*my_args, int);

	write(1, &current_char, 1);

	return (1);
}

int write_d(va_list *my_args)
{
	int result = 0, count = 0, i;
	char *str;
	char digit;
	int digits;
	result = va_arg(*my_args, int);

	if (result < 0)
	{
		result = -result;
		write(1, "-", 1);
		count++;
	}
	if (result <= 9)/* only one digit coming */
	{
		digit = ('0' + result);
		write(1, &digit, 1);
		count++;
		return (count);
	}
	while ((result / 10) > 10 * (i + 1))/* checks how many digits are coming */
	{
		i++;
	}
	digits = i + 2;/* total of digits to print = str_len */
	str = malloc(sizeof(char) * (digits + 1));

	for (i = 0; i < digits; i++)/* storing nums in str in reverse */
	{
		if (result >= 10)
			str[digits - 1 - i] = ('0' + (result % 10));
		else
			str[digits -1 - i] = ('0' + result);

		result /= 10;
	}
	for(i = 0; i < digits; i++)
	{
		write(1, &str[i], 1);
		count++;
	}
	free(str);
	return (count);
}
