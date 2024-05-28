#ifndef _STDIO_H_
#define _STDIO_H_

#define _IOFBF 1
#define _IOLBF 2
#define _IONBF 4
#define BUFSIZ 4096

#ifdef __cplusplus
extern "C"
{
#endif

#define __need_size_t
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>

#define SEEK_SET 0 /*unspecified*/
#define SEEK_CUR 1 /*unspecified*/
#define SEEK_END 2 /*unspecified*/

    typedef int FILE;

    extern const int fd_stdin;
    extern const int fd_stdout;
    extern const int fd_stderr;

#define stdin &fd_stdin
#define stdout &fd_stdout
#define stderr &fd_stderr

    static const int EOF = -1; // MACRO???

    int getchar();
    int printf(const char *format, ...);
    int scanf(const char *format, ...);
    char *fgets(char *str, int n, FILE *stream);
    int fgetc(FILE *stream);
    static inline int getc(FILE *stream) { return fgetc(stream); };
    int fputc(int ch, FILE *stream); // TODO
    static inline int putc(int ch, FILE *stream) { return fputc(ch, stream); };
    long ftell(FILE *stream);
    int fseek(FILE *stream, long offset, int origin);
    int fprintf(FILE *stream, const char *format, ...);
    int sprintf(char *dest, const char *format, ...);
    int vfprintf(FILE *stream, const char *format, va_list arg);
    int vprintf(const char *format, va_list arg);
    int vsprintf(char *s, const char *format, va_list arg);
    int vsnprintf(char *s, size_t n, const char *format, va_list arg);
    int snprintf(char *s, size_t n, const char *format, ...);

    int sscanf(const char *ibuf, const char *fmt, ...);
    int vsscanf(const char *inp, char const *fmt0, va_list ap);
    int fscanf(FILE *stream, const char *format, ...);
    int vfscanf(FILE *stream, const char *format, va_list arg);

    int mkdir(const char *pathname);
#ifdef __cplusplus
}
#endif

#endif
