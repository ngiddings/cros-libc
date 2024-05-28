CC = aarch64-none-elf-gcc
CXX = aarch64-none-elf-g++
AS = aarch64-none-elf-as
AR = aarch64-none-elf-ar
prefix:=$(HOME)/.cros/root

objs = src/aarch64/crt0.o src/uinit.o src/unistd.o src/mkdir.o src/stdio/fgets.o src/stdio/getchar.o\
	src/stdio/print/fprintf.o src/stdio/print/printf.o src/stdio/print/sprintf.o src/stdio/print/vsprintf.o src/stdio/print/snprintf.o src/stdio/print/vfprintf.o src/stdio/print/vprintf.o src/stdio/print/vsnprintf.o \
	src/heap/heap.o src/string.o src/stdlib/stdlib.o src/stringclass.o src/dirent.o src/execve.o src/fork.o src/wait.o\
	src/stdio/stdin.o src/stdio/fgetc.o src/stdio/file/fio.o src/stdio/scan/scanf.o src/stdio/scan/sscanf.o src/stdio/scan/vsscanf.o\
	src/stdio/scan/vscanf.o src/stdio/scan/vfscanf.o src/stdio/scan/fscanf.o\
	 

libname = libc.a
libmname = libm.a
libsys = libsyscall.a

CFLAGS = -I$(prefix)/include -iquote include/ -Isrc/  -lsyscall -ffreestanding -fpermissive -Wall -Wextra -ggdb -O0
CXXFLAGS = -I$(prefix)/include -iquote include/ -Isrc/ -ffreestanding -fpermissive -fno-exceptions -fno-rtti -Wall -Wextra -ggdb -O0

.PHONY: all
all: $(libname) $(libmname)

.PHONY: clean
clean:
	rm -f $(objs) $(libname)

.PHONY: install
install:
	mkdir -p $(prefix)/include
	mkdir -p $(prefix)/lib
	cp $(libname) $(prefix)/lib
	cp $(libmname) $(prefix)/lib
	cp include/*.h $(prefix)/include
	cp include/string $(prefix)/include
	cp include/vector $(prefix)/include

$(libname): $(objs)
	$(AR) rcs $@ $^ 

$(libmname):
	$(AR) rcs $@