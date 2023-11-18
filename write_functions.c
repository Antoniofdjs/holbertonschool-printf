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
