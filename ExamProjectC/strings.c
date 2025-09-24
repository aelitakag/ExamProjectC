#include "strings.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* my_strcpy(const char* src, char c) {
    size_t keep = 0;
    for (const char* p = src; *p; ++p)
        if (*p != c) ++keep;

    char* out = (char*)malloc(keep + 1);
    if (!out) return NULL;

    char* w = out;
    for (const char* p = src; *p; ++p)
        if (*p != c) *w++ = *p;
    *w = '\0';

    return out;
}

void n_words(int n, const void* p) {
    const char* cur = (const char*)p;
    for (int i = 0; i < n; ++i) {
        printf("%s\n", cur);
        cur += strlen(cur) + 1;  // move past the '\0' to the next string
    }
}
