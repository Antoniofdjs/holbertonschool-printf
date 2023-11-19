#ifndef MAIN_H
#define MAIN_H
typedef struct {
	char *type;
	int (*f)(va_list *);
}data;
int _printf(const char *format, ...);
int my_write_cs(va_list *my_args);
int write_s(va_list *my_args);
int write_c(va_list *my_args);
int write_d(va_list *my_args);
int write_x(va_list *my_args);
int write_p(va_list *my_args);
#endif
