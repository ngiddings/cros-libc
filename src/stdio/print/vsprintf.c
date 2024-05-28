#include "stdio.h"
#include <stddef.h>
#include "string.h"

/*started by Kyle Clements
    Stolen from Nathan...
    adjust libraries to match kernal*/

enum format_flags_t {
  FORMAT_PADDING = '0',
  FORMAT_WIDTH = '*',

  FORMAT_SIGNED_DECIMAL = 'i',
  FORMAT_UNSIGNED_DECIMAL = 'u',
  FORMAT_UNSIGNED_OCTAL = 'o',
  FORMAT_UNSIGNED_HEX = 'x',
  FORMAT_STRING = 's',
  FORMAT_CHARACTER = 'c',
  FORMAT_COUNT = 'n',
  FORMAT_PERCENT = '%',
  FORMAT_DIGIT = 'd'

};

static char *itoa(unsigned int n, unsigned int base, unsigned int width) {
  if (base < 2 || base > 16) {
    return NULL;
  }
  static const char *digits = "0123456789abcdef";
  static char buffer[65];
  char *s = &buffer[64];
  *s = 0;
  unsigned int count = 0;
  do {
    *--s = digits[n % base];
    n /= base;
    count++;
  } while (count < width || n != 0);
  return s;
}

static char *copyString(char *str, char *s) {
  int i;
  for (;;) {
    if (*str == '\0') {
      return s;
    }
    *s = *str;
    s++;
    str++;
  }
  return s;
}

int vsprintf(char *dest, const char *format, va_list valist) {

  while (*format) {
    if (*format == '%') {
      size_t width = 0;
      bool padding = false;
      switch (*++format) {
      case FORMAT_PADDING:
        padding = true;
        format++;
        break;
      }
      while (*format >= '0' && *format <= '9') {
        width = (width * 10) + *format - '0';
        format++;
      }
      switch (*format) {
      case FORMAT_SIGNED_DECIMAL:
      case FORMAT_DIGIT: {
        int n = va_arg(valist, int);
        if (n < 0) {
          *dest = '-';
          dest++;
          n *= -1;
        }
        dest = copyString(itoa((unsigned int)n, 10, width), dest);
        break;
      }
      case FORMAT_UNSIGNED_DECIMAL:
        dest = copyString(itoa(va_arg(valist, unsigned int), 10, width), dest);
        break;
      case FORMAT_UNSIGNED_OCTAL:
        dest = copyString(itoa(va_arg(valist, unsigned int), 8, width), dest);
        break;
      case FORMAT_UNSIGNED_HEX:
        dest = copyString(itoa(va_arg(valist, unsigned int), 16, width), dest);
        break;
      case FORMAT_STRING:
        dest = copyString(va_arg(valist, const char *), dest);
        break;
      case FORMAT_CHARACTER:
        dest = copyString(va_arg(valist, unsigned int), dest);
        break;
      case FORMAT_PERCENT:
        *dest = '%';
        dest++;
        break;
      }
    } else {
      *dest = *format;
      dest++;
    }
    format++;
  }
  // va_end(valist);
  *dest = '\0';
  return 0;
}
