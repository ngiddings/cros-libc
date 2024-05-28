#include "stdio.h"
#include "string.h"

/*started by Kyle Clements
    
    I am using the convention that whoever starts 
    the va_list has to end it.
    
    Will also need to adjust the target when a 
    kernal call allows us to change print locations*/


int vfprintf(FILE * stream, const char *format, va_list valist){
    
    static char strBuffer[1024];
    char *s = strBuffer;
    vsprintf(s, format, valist);
    write(*stream, strBuffer, strlen(strBuffer)); //this will need to change
    return 0;
}