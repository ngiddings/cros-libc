#ifndef _DIRENT_H
#define _DIRENT_H

#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned long ino_t;
typedef signed int off_t;

typedef struct dirent {
    ino_t d_ino;
    off_t d_off;
    unsigned short d_reclen;
    unsigned char d_type;

    char d_name[];
} DIR; 

enum
  {
    DT_UNKNOWN = 0,
# define DT_UNKNOWN        DT_UNKNOWN
    DT_FIFO = 1,
# define DT_FIFO        DT_FIFO
    DT_CHR = 2,
# define DT_CHR                DT_CHR
    DT_DIR = 4,
# define DT_DIR                DT_DIR
    DT_BLK = 6,
# define DT_BLK                DT_BLK
    DT_REG = 8,
# define DT_REG                DT_REG
    DT_LNK = 10,
# define DT_LNK                DT_LNK
    DT_SOCK = 12,
# define DT_SOCK        DT_SOCK
    DT_WHT = 14
# define DT_WHT                DT_WHT
  };

int alphasort(const struct dirent **, const struct dirent **);
int closedir(DIR *);
int dirfd(DIR *);
DIR *fdopendir(int);
DIR *opendir(const char *);
struct dirent *readdir(DIR *);
int readdir_r(DIR *restrict, struct dirent *restrictis, struct dirent **restricts);
void rewinddir(DIR *);
int scandir(const char *, struct dirent ***, int (*)(const struct dirent *), int (*)(const struct dirent **, const struct dirent **));
void seekdir(DIR *, long);
long telldir(DIR *);

#ifdef __cplusplus
}
#endif

#endif