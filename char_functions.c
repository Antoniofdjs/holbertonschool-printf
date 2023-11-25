#include "main.h"

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
		write(1, "(null)", 6);
		return (6);
	}
	if (*current_str == '\0')
		return (0);
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
	
	write(1, &current_char, 1);
	return (1);
}

/**
 *write_unknown - writes when no case found after a % match
 *@format: current char from format in _printf fucntion
 *Return: total count of characters
 */

int write_unknown(const char *format)
{
	if (*format == '\0')
		return (-1);

	write(1, "%", 1); /*print first % matched and char after*/
	write(1, format, 1); /*make a function call for this*/
	return (2);/* we stillmissing return -1 */
}

/**
 *write_mod - writes mod when two % are found
 *@format: current char from format in _printf fucntion
 *Return: total count of characters
 */

int write_mod(const char *format)
{
	(void)format;
	write(1, "%", 1);
	return (1);
}
