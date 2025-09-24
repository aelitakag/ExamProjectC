#ifndef MEMORY_H
#define MEMORY_H

#include <stddef.h>   // for size_t

// A function that simulates realloc
// ptr - pointer to existing memory block (or NULL)
// old_size - size of the previous allocation (in bytes)
// size - new size (in bytes)
// Returns a pointer to the new block, or NULL on error
void* my_realloc(void* ptr, size_t old_size, size_t size);

#endif
