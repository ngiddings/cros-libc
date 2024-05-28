#include "stdio.h"
#include "string.h"
#include <sys/syscall.h>
// #include <sys/syscall.h>
/*started by Kyle Clements*/

int printf(const char *format, ...) {
  static char strBuffer[1024];
  char *s = strBuffer;
  va_list valist;
  va_start(valist, format);
  vsprintf(s, format, valist);
  write(1, strBuffer, strlen(strBuffer));
  va_end(valist);
  return 0;
}
