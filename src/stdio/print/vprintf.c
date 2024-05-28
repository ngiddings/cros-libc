#include "stdio.h"
#include "string.h"

/*started by Kyle Clements
    
    Also, I am using the convention 
    that whoever starts the va_list has to end it*/


int vprintf(const char *format, va_list arg){
    static char strBuffer[1024];
    char *s = strBuffer;
    vsprintf(s, format, arg);
    write(1, strBuffer, strlen(strBuffer));
    return 0;
}