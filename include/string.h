#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *ptr1, const void *ptr2, size_t n);
void *memset(void *ptr, int value, size_t num);

char *strcpy(char *dest, const char *src);
char *strncpy(char *dest, const char *src, size_t n);
int strcmp(const char *str1, const char *str2);
int strncmp(const char *str1, const char *str2, size_t n);
char *strcat(char *dest, const char *src);
char *strncat(char *dest, const char *src, size_t n);
size_t strlen(const char *str);

// useless stuff

int strcoll(const char *str1, const char *str2);
size_t strxfrm(char *dest, const char *src, size_t n);
const void *memchr(const void *ptr, int val, size_t n);
const char *strchr(const char *str, int c);
size_t strcspn(const char *str1, const char *str2);
const char *strpbrk(const char *str1, const char *str2);
const char *strrchr(const char *str, int c);
size_t strspn(const char *str1, const char *str2);
const char *strstr(const char *str1, const char *str2);
char *strtok(char *str, const char *delims);
char *strerror(int errnum);

#ifdef __cplusplus
}
#endif

#endif
