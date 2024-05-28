#include <stdarg.h>
#include "stdio.h"

int sscanf(const char *ibuf, const char *fmt, ...)
{
	va_list ap;
	int ret;
	
	va_start(ap, fmt);
	ret = vsscanf(ibuf, fmt, ap);
	va_end(ap);
	return ret;
}