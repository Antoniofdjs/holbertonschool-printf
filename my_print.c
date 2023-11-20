#include <stdio.h>
#include "main.h"
#include "string.h"
#include <unistd.h>
#include "stdarg.h"

int _printf(const char *format, ...)
{
	va_list my_args;
	int i = 0, j, total_count = 0;
	data my_data[] = {
		{"s", write_s},
		{"c", write_c},
		{"d", write_d},
		{"i", write_d},
		{"x", write_x},
		{"X", write_x},
		{"p", write_p},
		{"%", write_mod},
		{NULL, NULL}
	};

	va_start(my_args, format);
	while (format[i] != '\0' && format != NULL)
	{
		if (format[i] == '%')
		{
			i++;
			for(j = 0; my_data[j].f != NULL; j++)
			{
				if (*my_data[j].type == format[i])
				{
					total_count += my_data[j].f(my_args, &format[i]);
					break;
				}
			}
		} else {
			write(1, &format[i], 1);
			total_count++;
		}
		i++;
	}
	va_end(my_args);
	return (total_count);
}
