#include "stdio.h"

//not the correct implementation but is here to do something

int vfscanf(FILE * stream, const char * format, va_list arg){
    char buffer[100];
    char *b = buffer;
    fgets(b, 100, stream);
    return vsscanf(b, format, arg);
}