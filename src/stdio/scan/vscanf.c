#include <stdarg.h>
#include "stdio.h"

int vscanf(const char *format, va_list arg)
{
    char mystring[100];
    int ret;
    fgets(mystring, 99, stdin);
    ret = vsscanf(mystring, format, arg);
    return ret;
}