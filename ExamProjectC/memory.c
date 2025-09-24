#include "memory.h"
#include <stdlib.h>
#include <string.h>

void* my_realloc(void* ptr, size_t old_size, size_t size) {
    // If the new size is zero → free and return NULL
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    // If the pointer is NULL → behave like malloc
    if (ptr == NULL) {
        return malloc(size);
    }

    // Allocate a new block
    void* np = malloc(size);
    if (!np) {
        return NULL; // Allocation failed
    }

    // Copy contents from old block to new block
    size_t to_copy = old_size < size ? old_size : size;
    memcpy(np, ptr, to_copy);

    // Free the old block
    free(ptr);

    return np;
}
