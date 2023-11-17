#include <stdio.h>
#include "main.h"
#include "string.h"
#include <unistd.h>
#include "stdarg.h"

int _printf(const char *format, ...)
{
	int case_count = 0;/* on/off switch for cases*/
	int i = 0;

	while (format != NULL && format[i] != '\0')
	{
		case_count = 0;
		if (format[i] == '%')
		{
			i++;/* to check char after %"_" */
			switch (format[i])
			{
				case 'c':
					write(1, "-PRINTC-", 8);/* place holder for call function */
					case_count++;
					break;

				case 's':
					write(1, "-PRINTS-", 8);/*place holder for call function*/
					case_count++;
					break;

				case 'd':
					write(1, "-PRINTD-", 8);
					case_count++;
					break;

				case 'i':
					write(1, "-PRINTI-", 8);
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
	return (0);
}
