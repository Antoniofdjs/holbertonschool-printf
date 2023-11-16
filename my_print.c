#include <stdio.h>
#include "main.h"
#include "string.h"
#include <unistd.h>
#include "stdarg.h"

int _printf(const char *format, ...)
{
	int case_count = 0;/*on/off switch for cases*/
	int i = 0;

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{	case_count = 0;
			i++;
			switch (format[i])/*falta add los functions calls para printear los cases*/
			{
				case 'c':
					printf("-PRINTC-");
					case_count++;
					break;
				case 's':
					printf("-PRINTS-");
					case_count++;
					break;
				case '%':
					write(1, &format[i], 1);
					case_count++;
					break;
				default:
					i--;
			}
		}
		if (case_count == 0)
			write(1, &format[i], 1);
		i++;
	}
	return (0);
}
