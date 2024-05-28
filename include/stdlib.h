#ifndef CROS_STDLIB_H
#define CROS_STDLIB_H

#include <stddef.h>
#include "stdio.h"

#ifdef __cplusplus
extern "C" {
#endif

int dup(int fd);
int dup2(int oldfd, int newfd);  // I NEED dup2() FOR THE SHELL -connor
int fork(); // TODO:
int wait(int *addr); // TODO:
void exit(int status); // TODO:

FILE *fopen(const char *filename, const char *mode); // TODO:
int *fclose(FILE *stream); // TODO:

void* malloc(size_t size);
void* realloc(void* ptr, size_t size);
void free(void* ptr);

int rand(void);
void srand(unsigned int seed);

//conversions
double atof (const char* str);
long int atol (const char* str);
long long atoll (const char * str);
int atoi (const char * str);

double strtod (const char* str, char** endptr);
float strtof (const char* str, char** endptr);
long double strtold (const char* str, char** endptr);
long int strtol (const char* str, char** endptr, int base);
long long int strtoll (const char* str, char** endptr, int base);
unsigned long int strtoul (const char* str, char** endptr, int base);
unsigned long long int strtoull (const char* str, char** endptr, int base);

#ifdef __cplusplus
}
#endif

#endif