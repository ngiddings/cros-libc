#ifndef _KERNEL_HEAP_H
#define _KERNEL_HEAP_H

#include <stdint.h>
#include "string.h"
#include <sys/syscall.h>

#define WORD_SIZE sizeof(unsigned long) // Either 4 or 8, we're 64 bit so 8
#define OVERHEAD 5
#define ALIGN(size) (((size) + (WORD_SIZE - 1)) & ~(WORD_SIZE - 1))
#define SIZE_T_SIZE (ALIGN(sizeof(unsigned long))) // header size

void init_heap(void *heap_ptr, unsigned long mem_size);

void *malloc_heap(unsigned long size);

void free_heap(void *ptr);

void rebuild_list(unsigned long *current);

void *realloc_heap(void *, unsigned long new_size);

// Testing functions
#define SIZE 30

void debug_bounds_check(unsigned long *a, unsigned long *b, uint64_t size_b);
uint64_t xorshift64(uint64_t state);
uint64_t randinrange(uint64_t lower, uint64_t upper, uint64_t rand);

struct test_struct
{
  unsigned long *pointer;
  int size;
};

#endif
