#include "heap/heap.h"
#include "stdio.h"
#include <sys/syscall.h>

/* need to know the h files for kernal and the h file
    for the h file for the userspace*/

void uinit()
{
  printf("C library starting...\n");

  // Heap Initialization
  unsigned long heap_ptr = 0x200000000;
  unsigned long mem_size = (1 << 20);
  mmap((void *)heap_ptr, mem_size, 1);
  init_heap((void *)heap_ptr, mem_size);
}
