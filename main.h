#ifndef MAIN_H
#define MAIN_H
typedef struct {
	char *type;
	int (*f)();
}data;
int _printf(const char *format, ...);
int my_write_cs(va_list *my_args);
int write_s(va_list *my_args);
int write_c(va_list *my_args);
int write_d(va_list *my_args);
int write_x(va_list *my_args, const char *current_letter);
int write_p(va_list *my_args);
#endif
