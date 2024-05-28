#include "unistd.h"
#include <sys/syscall.h>

int *getcwd(char *, size_t)
{
    return 0;
}

int fchdir(int fd)
{
    return 0;
}

int chdir(const char *path)
{
    return 0;
}

int close(int fd)
{
    return 0;
}

int open(int fd)
{
    return 0;
}

int pipe(int fildes[2])
{
    return 0;
}
