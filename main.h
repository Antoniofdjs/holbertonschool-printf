#ifndef MAIN_H
#define MAIN_H
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * data- Structure represents data types and their corresponding functions
 *
 * @type: Matching letters for the data type
 * @f: Pointer function  that handles the specified data type
 *
 * Description:
 * Structure is used for matching chars from a string
 * passed into my '_printf' and associate them to a function.
 * A pointer function calls the function to handle the data
 */

typedef struct
{
	char *type;/* Matching letters for data type */
	int (*f)();/* Pointer to a function that handles the data */
} data;
int _printf(const char *format, ...);
int my_write_cs(va_list *my_args);
int write_s(va_list *my_args);
int write_c(va_list *my_args);
int write_d(va_list *my_args);
int write_u(va_list *my_args);
int write_x(va_list *my_args, const char *format);
int write_o(va_list *my_args);
int write_p(va_list *my_args);
int write_mod(const char *format);
int write_unknown(const char *format);
#endif
