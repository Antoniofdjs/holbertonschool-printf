#include <stdio.h>
#include "main.h"
#include "string.h"
#include <unistd.h>
#include "stdarg.h"

int my_write_cs(va_list *my_args)
{
	char *current_str = va_arg(my_args, char *);
	int j = 0;
	int coutn = 0;

	while (current_str != NULL && current_str[j] != '\0')
	{
		write(1, current_str[j], 1);
		j++;
		count++;
	}

	return (count);
}
