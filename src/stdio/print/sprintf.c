#include "stdio.h"

/*started by Kyle Clements*/

int sprintf(char *dest, const char *format, ...){
    
    va_list valist;
    va_start(valist, format);
    vsprintf(dest, format, valist);
    va_end(valist);
    return 0;
}