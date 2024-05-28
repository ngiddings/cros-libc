#include "dirent.h"
#include <stddef.h>

int alphasort(const struct dirent **, const struct dirent **) {
    printf("Not implemented");
    return 0;
}
int closedir(DIR *) {
    printf("Not implemented");
    return 0;
}
int dirfd(DIR *) {
    printf("Not implemented");
    return 0;
}
DIR *fdopendir(int) {
    printf("Not implemented");
    return NULL;
}
DIR *opendir(const char *) {
    printf("Not implemented");
    return NULL;
}
struct dirent *readdir(DIR *) {
    printf("Not implemented");
    return NULL;
}
int readdir_r(DIR *restrict, struct dirent *restrict, struct dirent **restrict) {
    printf("Not implement");
    return NULL;
}
void rewinddir(DIR *) {
    printf("Not implemented");
}
int scandir(const char *, struct dirent ***, int (*)(const struct dirent *), int (*)(const struct dirent **, const struct dirent **)) {
    printf("Not implemented");
    return 0;
}
void seekdir(DIR *, long) {
    printf("Not implemented");
}
long telldir(DIR *) {
    printf("Not implemented");
    return 0;
}