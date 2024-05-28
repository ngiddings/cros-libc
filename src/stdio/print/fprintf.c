#include "stdio.h"
#include "string.h"
#include <sys/syscall.h>

/*started by Kyle Clements
    Stolen from Nathan...
    adjust libraries to match kernal

    Will need to adjust to actually target files.
    Will need an updated part of this on kernal side.*/

int fprintf(FILE *stream, const char *format, ...)
{

    va_list valist;
    va_start(valist, format);
    static char strBuffer[1024];
    char *s = strBuffer;
    vsprintf(s, format, valist);
    va_end(valist);
    write(*stream, strBuffer, strlen(strBuffer));
    return 0;
}