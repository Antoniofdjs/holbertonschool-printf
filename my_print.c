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
		{NULL, NULL}
	};
	
	va_start(my_args, format);
	while (format[i] != '\0' && format != NULL)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
				total_count++;
			}
			j = 0;
			while (my_data[j].f != NULL)
			{
				if (*my_data[j].type == format[i])
				{
					total_count += my_data[j].f(&my_args);
					break;
				}
				j++;
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
