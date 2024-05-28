#ifndef _UNISTD_H
#define _UNISTD_H

#include <stddef.h>
#ifdef __cplusplus
extern "C"
{
#endif

#include <types/pid.h>

	int execve(const char *path, char *argv[],
			   char const *envp[]);
	int execvp(const char *file, char const *argv[]);
	int *getcwd(char *, size_t);
	int close(int fd);
	int open(int fd);
	int chdir(const char *path);
	int pipe(int fildes[2]);

#ifdef __cplusplus
}
#endif

#endif