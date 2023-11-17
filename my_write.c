#include <stdarg.h>
#include <stdio.h>
#include "main.h"
#include <unistd.h>
int my_write_cs(va_list *my_args)
{
    char *current_str;
    int j = 0;
    int count = 0;

    va_list args_copy;
    va_copy(args_copy, *my_args);
    current_str = va_arg(args_copy, char *);

    while (current_str != NULL && current_str[j] != '\0')
    {
        write(1, &current_str[j], 1);
        j++;
        count++;
    }

    va_end(args_copy);
    return (count);
}
