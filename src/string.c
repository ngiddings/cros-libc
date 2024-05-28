#include "../include/string.h"
#include "stdlib.h"

void *memcpy(void *dest, const void *src, size_t n)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;

    for (size_t i = 0; i < n; i++)
        d[i] = s[i];

    return dest;
}

void *memmove(void *dest, const void *src, size_t n)
{
    char *d = (char *)dest;
    const char *s = (const char *)src;

    for (size_t i = n; i > 0; i--)
        d[i - 1] = s[i - 1];

    return dest;
}

int memcmp(const void *ptr1, const void *ptr2, size_t n)
{
    const unsigned char *s1 = (const unsigned char *)ptr1;
    const unsigned char *s2 = (const unsigned char *)ptr2;

    return strcmp(s1, s2);
}

void *memset(void *ptr, int value, size_t num)
{
    unsigned char *p = (unsigned char *)ptr;
    unsigned char v = (unsigned char)value;

    for (size_t i = 0; i < num; i++)
        p[i] = v;

    return ptr;
}

char *strcpy(char *dest, const char *src)
{
    char *temp = dest;

    while (*src)
    {
        *temp = *src;
        temp++;
        src++;
    }
    *temp = '\0';

    return dest;
}

char *strncpy(char *dest, const char *src, size_t n)
{
    if (dest != NULL)
        free(dest);

    dest = (char *)malloc(sizeof(char) * (n + 1));
    char *temp = dest;

    while (*src && n > 0)
    {
        *temp = *src;
        temp++;
        src++;
        n--;
    }
    *temp = '\0';

    return dest;
}

int strcmp(const char *str1, const char *str2)
{
    while (*str1 && *str2 && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return *str1 == *str2;
}

int strncmp(const char *str1, const char *str2, size_t n)
{
    while (*str1 && *str2 && *str1 == *str2 && n > 0)
    {
        str1++;
        str2++;
        n--;
    }
    return *str1 == *str2;
}

char *strcat(char *dest, const char *src)
{
    if (dest == NULL)
    {
        return strcpy(dest, src);
    }

    int len_dest = strlen(dest);
    int len_src = strlen(src);
    // char *temp = (char *)malloc(sizeof(char) * (len_dest + len_src + 1));

    // char *temp_ptr = temp;
    char *dest_ptr = dest + len_dest;
    const char *src_ptr = src;

    /*while (*dest_ptr)
    {
        *temp_ptr = *dest_ptr;
        temp_ptr++;
        dest_ptr++;
    }*/

    while (*src_ptr)
    {
        *dest_ptr = *src_ptr;
        dest_ptr++;
        src_ptr++;
    }
    *dest_ptr = '\0';

    // free(dest);
    // dest = temp;

    return dest;
}

char *strncat(char *dest, const char *src, size_t n)
{
    if (dest == NULL)
    {
        dest = strcpy(dest, src);
        return;
    }

    int len_dest = strlen(dest);
    int len_src = strlen(src);
    char *temp = (char *)malloc(sizeof(char) * (len_dest + n + 1));

    char *temp_ptr = temp;
    const char *dest_ptr = dest;
    const char *src_ptr = src;

    while (*dest_ptr)
    {
        *temp_ptr = *dest_ptr;
        temp_ptr++;
        dest_ptr++;
    }

    while (*src_ptr && n > 0)
    {
        *temp_ptr = *src_ptr;
        temp_ptr++;
        src_ptr++;
        n--;
    }
    *temp_ptr = '\0';

    free(dest);
    dest = temp;

    return dest;
}

size_t strlen(const char *str)
{
    int len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return len;
}

// useless stuff

int strcoll(const char *str1, const char *str2)
{
    printf("el no implemento");
    return 0;
}

size_t strxfrm(char *dest, const char *src, size_t n)
{
    printf("el no implemento");
    return 0;
}

const void *memchr(const void *ptr, int val, size_t n)
{
    printf("el no implemento");
    return 0;
}

const char *strchr(const char *str, int c)
{
    printf("el no implemento");
    return 0;
}

size_t strcspn(const char *str1, const char *str2)
{
    printf("el no implemento");
    return 0;
}

const char *strpbrk(const char *str1, const char *str2)
{
    printf("el no implemento");
    return 0;
}

const char *strrchr(const char *str, int c)
{
    printf("el no implemento");
    return 0;
}

size_t strspn(const char *str1, const char *str2)
{
    printf("el no implemento");
    return 0;
}

char *strtok(char *str, const char *delims)
{
    printf("el no implemento");
    return 0;
}

const char *strstr(const char *str1, const char *str2)
{
    if (*str2 == '\0')
        return str1;

    while (*str1 != '\0')
    {
        const char *ptr1 = str1;
        const char *ptr2 = str2;

        while (*ptr1 != '\0' && *ptr2 != '\0' && *ptr1 == *ptr2)
        {
            ptr1++;
            ptr2++;
        }

        if (*ptr2 == '\0')
            return str1;

        str1++;
    }

    return NULL;
}