#include "stdlib.h"
#include <sys/syscall.h>

void sigchild_ret()
{
    sigret();
}

void sigchild(void *userdata)
{
    *(int *)userdata = 0;
}

int signal_set = 0;

/*Started by Kyle Clements
    this is all kernel.
    we can use this as a wrapper for user side*/
int wait(int *addr)
{
    int waiting = 1;
    if (!signal_set)
    {
        sigaction(17, sigchild, sigchild_ret, (void *)&waiting);
    }
    while (waiting)
    {
        sigwait();
    }
    return 0;
}