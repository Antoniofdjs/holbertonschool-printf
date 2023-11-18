#ifndef MAIN_H
#define MAIN_H
typedef struct {
	char *type;
	int (*f)(va_list *);
}data;
int _printf(const char *format, ...);
int my_write_cs(va_list *my_args);
#endif
