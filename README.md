# Exam Project – C Programming

## Overview
This project was developed as part of a programming course assignment.  
It demonstrates dynamic memory management, string manipulation, and linked list operations in **C**.  

The implementation is divided into three main parts:

1. **Memory (`memory.c` / `memory.h`)**  
   - Custom implementation of `my_realloc`.

2. **Strings (`strings.c` / `strings.h`)**  
   - `my_strcpy`: creates a copy of a string without all occurrences of a given character.  
   - `n_words`: prints `n` consecutive null-terminated strings from a memory block.

3. **Linked List (`linkedlist.c` / `linkedlist.h`)**  
   - `remove_at`: removes a node at a given index.  
   - `circle_exists`: detects if the list contains a cycle.  
   - `size_of_circle`: returns the cycle size (0 if none).

A test driver (`main.c`) is included to demonstrate and validate the functionality of all parts.

---

## File Structure
```
├── memory.h
├── memory.c
├── strings.h
├── strings.c
├── linkedlist.h
├── linkedlist.c
├── main.c
└── README.md
```

---

## Compilation & Run

### GCC (Linux / macOS):
```bash
gcc main.c memory.c strings.c linkedlist.c -o exam_project
./exam_project
```

---

## MinGW (Windows)
```
gcc main.c memory.c strings.c linkedlist.c -o exam_project.exe
exam_project.exe
```

## Visual Studio (Windows)
1. Open the solution in Visual Studio.

2. Make sure the project is set to Compile as C Code (/TC).

3. Build → Run.


---

## Example Output

```bash
=== memory tests ===
1 2 3 4 5
1 2
arr == NULL ? yes

=== strings tests ===
my_strcpy("abacad", 'a') -> bcd
n_words(3, blob):
hello
world
C

=== linked list tests ===
Before remove_at: 10 20 30
After remove_at: 10 30
circle_exists -> found
size_of_circle -> 2
```


---

## Notes
The project is implemented in C (C89/C99 standard).

All memory allocations are checked for NULL to prevent dereferencing invalid pointers.

main.c includes demonstration tests; it is not part of the API but used for validation.

This project was compiled and tested both on Linux (GCC) and Windows (Visual Studio / MinGW).
