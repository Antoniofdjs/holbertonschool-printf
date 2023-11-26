#include "main.h"

/**
 * _printf - Recreates the 'printf' function from C
 * @format: A string that specifies the format output.
 *			It can contain regular chars and format specs.
 * Return: int total of chars printed
 */

int _printf(const char *format, ...)
{
	va_list my_args;
	int i = 0, j, total_count = 0, conteo_function = 0;
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
		{"b", write_b},
		{NULL, NULL} /* type / f */
	};
	va_start(my_args, format);
	if (format == NULL)
		return (-1);/* we need to do this all func */
	for (i = 0; format[i] != '\0' && format != NULL; i++)/*string still exists*/
	{
		if (format[i] == '%')/* match a % first time */
		{
			i++;
			for (j = 0; my_data[j].f != NULL; j++)/*Still have functions to call*/
			{
				if (*my_data[j].type == format[i])/* Matched a case */
				{
					total_count += my_data[j].f(my_args, &format[i]);
					break;
				}
			}
			if (j == 11)/*unknown char after %, match data[j]. =  null*/
			{
				conteo_function = write_unknown(&format[i]);
				if (conteo_function == -1)
					return (-1);

				total_count += conteo_function;
			}
		}
			else/* no % found */
			total_count += write_default(&format[i]);
	}
		va_end(my_args);
		return (total_count);
}
