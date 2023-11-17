#ifndef MAIN_H
#define MAIN_H
typedef struct {
	char *type;
	void (*f)();
}data;
int _printf(const char *format, ...);
#endif
