#ifndef MAIN_H
#define MAIN_H

/**
 * struct data - Represents data types and their corresponding functions
 * @type: Matching letters for the data type
 * @f: Pointer function  that handles the specified data type
 */

typedef struct
{
	char *type;
	int (*f)();
} data;
int _printf(const char *format, ...);
int my_write_cs(va_list *my_args);
int write_s(va_list *my_args);
int write_c(va_list *my_args);
int write_d(va_list *my_args);
int write_x(va_list *my_args, const char *format);
int write_p(va_list *my_args);
int write_mod(const char *format);
#endif
