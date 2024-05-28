#include "stdio.h"

/*started by Kyle Clements*/


int snprintf(char *dest, size_t n, const char *format, ...){
    
    va_list valist;
    va_start(valist, format);
    vsnprintf(dest, n, format, valist);
    va_end(valist);
    return 0;
}