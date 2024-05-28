#include "heap/heap.h"
#include "stdlib.h"
#include <sys/syscall.h>
/*Started by Kyle Clements
 */

/* started by Kyle Clements
    what this will need to do is use a system call to update this file
   descriptor to let the file system know that there is another reference to
   this "open" file. LOW PRIORITY*/
int dup(int fd)
{
  // TODO:
  return -1;
}

int dup2(int oldfd, int newfd)
{
  int fd = fddup(oldfd, newfd);
  if (fd < 0)
  {
    return -1;
  }
  return fd;
}

void *malloc(size_t size) { return malloc_heap(size); }

void *realloc(void *ptr, size_t size) { return realloc_heap(ptr, size); }
void free(void *ptr)
{
  // TODO:
  return free_heap(ptr);
}

void exit(int status)
{
  printf("not implemented yet");
}

FILE *fopen(const char *filename, const char *mode)
{
  FILE *f = malloc(sizeof(int));
  *f = openf(filename, 0);
  // printf("fopen %s\n", filename);
  return f;
}

int *fclose(FILE *stream)
{
  closef(*stream);
  // printf("fclose %i\n", *stream);
  if (*stream > fd_stderr)
  {
    free(stream);
  }
  // printf("Not implemented");
  return 0;
}

unsigned int rand_seed;

int rand(void)
{
  const unsigned int a = 1103515245;
  const unsigned int c = 12345;
  const unsigned int m = 0xFFFFFFFF;

  rand_seed = (a * rand_seed + c) % m;

  return rand_seed;
}

void srand(unsigned int seed) { rand_seed = seed; }

double atof(const char *str)
{
  double x = 0.0;

  int e = 0;
  int c = *str;
  int sign;
  int i;
  // remove white space
  while (c == ' ' || c == '\t' || c == '\n')
  { // is a space
    c = *str++;
  }
  // first check for initial numbers before decimal
  while (c != '\0' && (c >= '0' && c <= '9'))
  {
    x = x * 10.0 + (c - '0');
    c = *str++;
  }

  // check for decimal
  if (c == '.')
  {
    c = *str++;
    while (c != '\0' && (c >= '0' && c <= '9'))
    {
      // collect values and keep track of where the decimal should land
      x = x * 10.0 + (c - '0');
      e = e - 1;
      c = *str++;
    }
  }

  // if no decimal, we will check for e
  if (c == 'e' || c == 'E')
  {
    // assume positive number
    sign = 1;
    i = 0;
    c = *str++;
    if (c == '+')
    {
      c = *str++;
    }
    else if (c == '-')
    {
      c = *str++;
      sign = -1;
    }
    while ((c >= '0' && c <= '9'))
    {
      // collect
      i = i * 10 + (c - '0');
      c = *str++;
    }
    // track decimal position
    e = e + i * sign;
  }
  // now adjust decimal where needed
  while (e > 0)
  {
    x = x * 10;
    e--;
  }
  while (e < 0)
  {
    x = x * 0.1;
    e++;
  }
  return x;
}

long int atol(const char *str)
{
  long int x = 0;
  char c = *str;
  int sign = 1;
  // remove white space
  while (c == ' ' || c == '\t' || c == '\n')
  { // is a space
    c = *str++;
  }
  // check sign first
  if (c == '-')
  {
    sign = -1;
    c = *str++;
  }
  else if (c == '+')
  {
    c = *str++;
  }

  while (c >= '0' && c <= '9')
  {
    x = 10 * x + (c - '0');
    c = *str++;
  }

  return sign * x;
}

long long atoll(const char *str)
{
  long long x = 0;
  char c = *str;
  int sign = 1;
  // remove white space
  while (c == ' ' || c == '\t' || c == '\n')
  { // is a space
    c = *str++;
  }
  // check sign first
  if (c == '-')
  {
    sign = -1;
    c = *str++;
  }
  else if (c == '+')
  {
    c = *str++;
  }

  while (c >= '0' && c <= '9')
  {
    x = 10 * x + (c - '0');
    c = *str++;
  }

  return sign * x;
};

int atoi(const char *str)
{
  int x = 0;
  char c = *str;
  int sign = 1;
  // remove white space
  while (c == ' ' || c == '\t' || c == '\n')
  { // is a space
    c = *str++;
  }
  if (c == '-')
  {
    sign = -1;
    c = *str++;
  }
  else if (c == '+')
  {
    c = *str++;
  }
  while (c >= '0' && c <= '9')
  {
    x = 10 * x + (c - '0');
    c = *str++;
  }

  return sign * x;
}

double strtod(const char *str, char **endptr)
{
  char *s = str;
  double x = atof(s);
  if (endptr != NULL)
  {
    *endptr = s;
  }
  return x;
}

float strtof(const char *str, char **endptr)
{
  char *s = str;
  double x = atof(s);
  if (endptr != NULL)
  {
    *endptr = s;
  }
  return (float)x;
}

long double strtold(const char *str, char **endptr)
{
  printf("Not implemented");
  long double x = 0.0;
  return x;
}
long int strtol(const char *str, char **endptr, int base)
{
  printf("Not implemented");
  long int x = 0;
  if (base == 10 || base == 0)
  {
    char *s = str;
    atol(s);
    if (endptr != NULL)
    {
      *endptr = s;
    }
  }
  return x;
}
long long int strtoll(const char *str, char **endptr, int base)
{
  printf("Not implemented");
  long long x = 0;
  return x;
}
unsigned long int strtoul(const char *str, char **endptr, int base)
{
  printf("Not implemented");
  unsigned long int x = 0;
  return x;
}
unsigned long long int strtoull(const char *str, char **endptr, int base)
{
  printf("Not implemented");
  unsigned long long int x = 0;
  return x;
}
