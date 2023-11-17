#include <stdio.h>
#include "main.h"
#include "string.h"
#include <unistd.h>
#include "stdarg.h"

int _printf(const char *format, ...)
{
	va_list my_args;
	va_list args_copy;
	int case_count = 0;/* on/off switch for cases*/
	int i = 0, total_count = 0;

	va_start(my_args, format);
	va_copy(args_copy, my_args);
	while (format != NULL && format[i] != '\0')
	{
		case_count = 0;
		if (format[i] == '%')
		{
			i++;/* to check char after %"_" */
			switch (format[i])
			{
				case 's':
					total_count += my_write_cs(&args_copy);
					case_count++;
					break;

				case 'd':
				case 'i':
					write(1, "-PRINTD-", 8);
					case_count++;
					break;

				case 'u':
					write(1, "-PRINTU-", 8);
					case_count++;
					break;

				case 'p':
					write(1, "-PRINTP-", 8);
					case_count++;
					break;

				case 'r':
					write(1, "-PRINTR-", 8);
					case_count++;
					break;

				case 'x':
				case 'X':
					write(1, "-PRINTX-", 8);
					case_count++;
					break;

				case 'o':
					write(1, "-PRINTO-", 8);
					case_count++;
					break;

				case '%':
					write(1, &format[i], 1);
					case_count++;
					break;

				default:/* found % but no case after */
					i--;/* we go back to index with % */
			}
		}
		if (case_count == 0)/* if no cases where made */
			write(1, &format[i], 1);/* we write current index */
		i++;
	}
	va_end(args_copy);
	va_end(my_args);
	return (total_count);
}
