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
		{"u", write_u},
		{"i", write_d},
		{"x", write_x},
		{"X", write_x},
		{"p", write_p},
		{"%", write_mod},
		{"o", write_o},
		{NULL, NULL}
	};
	va_start(my_args, format);
	for (i = 0; format[i] != '\0' && format != NULL; i++)/*string still exists*/
	{
		if (format[i] == '%')/* match a % first time */
		{
			i++;
			for (j = 0; my_data[j].f != NULL; j++)/*Still have functions to call*/
			{
				if (*my_data[j].type == format[i])/* Matched a case */
				{
					total_count += my_data[j].f(my_args, &format[i]);/* call function */
					break;
				}
			}
			if (j == 10)/*unknown char after % match data[j]. =  null*/
			{
				total_count += write_unknown(&format[i]);
			}
		}
		else/* no % found */
		{
			write(1, &format[i], 1);
			total_count++;
		}
	}
	va_end(my_args);
	return (total_count);
}
