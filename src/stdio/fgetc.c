#include "stdio.h"
#include <sys/syscall.h>

int fgetc(FILE *stream)
{
    char c;
    int check;
    check = read(*stream, &c, 1);
    if (check < 0)
    {
        return -1; // eof
    }
    return c;
}

int fputc(int ch, FILE *stream)
{
    char c = ch;
    write(*stream, &c, 1);
    return 0;
}