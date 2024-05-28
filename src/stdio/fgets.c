#include <stddef.h>
#include "stdio.h"
#include "string.h"
#include <sys/syscall.h>
#include <types/status.h>

// this needs file read library, def of file
// started by kyle clements

// gets the space to store characters, the size of the space
// and where to read from

char *fgets(char *str, int n, FILE *stream)
{
    int i = 0, con = 0;
    char c;
    while (i + 1 < n)
    {
        con = read(*stream, &c, 1);
        if (con == EEOF)
        {
            if (i == 0)
                return NULL;
            break;
        }
        else if (con < 0)
        {
            // I/O failure
            return NULL;
        }
        else if (con == 0)
        { // file is smaller than wanted stored
            /*str[i++] = '\0';
            return str;*/
            yield();
            continue;
        }

        if (c == '\n' || c == '\0' || c == '\r')
        {
            str[i] = '\n';
            i++;
            break;
        }
        else
        {
            str[i] = c;
            i++;
        }
    }
    str[i++] = '\0';
    return str;
}
