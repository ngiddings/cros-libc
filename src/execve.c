#include "unistd.h"
#include "string.h"
#include <sys/syscall.h>

int execve(const char *path, char *argv[], char const *envp[])
{
    static char s[256];
    strcpy(s, "/bin/");
    strcat(s, path);

    // Try searching in /bin
    exec(s, argv, envp);

    // If that doesn't work, treat 'path' as absolute path
    exec(path, argv, envp);
    return 0;
}

int execvp(const char *path, const char *argv[])
{
    const char *envp[] = {NULL};
    static char s[256];
    strcpy(s, "/bin/");
    strcat(s, path);

    // Try searching in /bin
    exec(s, argv, envp);

    // If that doesn't work, treat 'path' as absolute path
    exec(path, argv, envp);
    return 0;
}