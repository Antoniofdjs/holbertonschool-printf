#include <stdio.h>
#include "main.h"
#include "string.h"
#include <unistd.h>
#include "stdarg.h"

int write_s(va_list *my_args)
{
    char *current_str;
    int j = 0;
    int count = 0;

    current_str = va_arg(*my_args, char *);

    while (current_str != NULL && current_str[j] != '\0')
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

int _printf(const char *format, ...)
{
	va_list my_args;
	int i = 0, j, total_count = 0;
	data my_data[] = {
		{"s", write_s},
		{"c", write_c},
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
				if (my_data[j].type[0] == format[i])
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
