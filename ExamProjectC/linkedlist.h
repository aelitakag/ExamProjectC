#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct link {
    int data;
    struct link* next;
    struct link* prev;
} link;

/* 1) Remove a node at the given index (0-based) */
void remove_at(link* head, int index);

/* 2) Detect a cycle: return a pointer to a node in the cycle (if exists), otherwise NULL */
link* circle_exists(link* head);

/* 3) Return the size of the cycle: if no cycle, return 0 */
int size_of_circle(link* head);

#endif
