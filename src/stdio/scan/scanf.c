#include <stdarg.h>
#include <stddef.h>
#include <stdbool.h>
#include "stdio.h"

/*Started by Kyle Clements

	scanf will always look into stdin*/

int scanf(const char *format, ...)
{
	char mystring[100];
	va_list args;
	int ret;
	va_start(args, format);
	fgets(mystring, 99, stdin);
	ret = vsscanf(mystring, format, args);
	va_end(args);
	return ret;
};