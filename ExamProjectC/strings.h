#pragma once
#ifndef STRINGS_H
#define STRINGS_H

// Returns a new copy of src without all occurrences of the character c
char* my_strcpy(const char* src, char c);

// Prints n consecutive null-terminated strings from a memory block separated by '\0'
void n_words(int n, const void* p);

#endif
