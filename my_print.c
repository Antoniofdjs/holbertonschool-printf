#include <stdio.h>
#include "main.h"
#include "string.h"
#include "stdarg.h"

/**
 * print_c - prints chars
 * @my_args: pointer to args
 */
void print_c(va_list *my_args)
{
	printf("%c", va_arg(*my_args, int));
}
/**
 * print_i - prints ints
 * @my_args: pointer to args
 */
void print_i(va_list *my_args)
{
	printf("%d", va_arg(*my_args, int));
}
/**
 * print_f - prints floats
 * @my_args: pointer to args
 */
void print_f(va_list *my_args)
{
	printf("%f", va_arg(*my_args, double));
	}
/**
 * print_s - prints strings
 * @my_args: pointer to args
 */
void print_s(va_list *my_args)
{
	char *current_str;

	current_str = va_arg(*my_args, char *);
	if (current_str == NULL)
		current_str = "(nil)";
	printf("%s", current_str);
}
/**
 * print_all - prints everything
 * @format: constant format string
 *
 * Return: void
 */
int _printf(const char *format, ...)
{
	int arg_count = 0;/*count for format args*/
	int i = 0, j = 0;
	va_list my_args;
	data my_data[] = {
		{"c", print_c},
		{"i", print_i},
		{"f", print_f},
		{"s", print_s},
		{NULL, NULL} /*letter-type, (function*) */
	};/*Struct char *type, void (*f)()*/

	va_start(my_args, format);


	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])/*falta add los functions calls para printear los cases*/
			{
				case 'c':
					arg_count++;
					break;
				case 's':
					arg_count++;
					break;
				case 'd':
					arg_count++;
					break;
			}
		}
		i++;
	};
	if (arg_count == 0)/* If there are no % cases*/
	{
	for (i = 0; format[i] != '\0'; i++)
			putchar(format[i]);
		return (0);
	};/*Codigo hasta aqui------------------------*/
	i = 0;
	while (format != NULL && format[i] != '\0') /*ESTA PARTE TODAVIA ARREGLANDO*/
	{
		j = 0;
		while (my_data[j].f != NULL)/*still have functions to call*/
		{
			if (*my_data[j].type == format[i])/*match letters = data type */
			{
				my_data[j].f(my_args);/*call matching print function */
				break;
			}
			j++;
		}
		i++;
	}

	va_end(my_args);
	printf("\n");
	return (0);
}
