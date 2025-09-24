#include "linkedlist.h"
#include <stdlib.h>

/* Helper: returns the node at the given index (0-based) or NULL if out of range */
static link* node_at(link* head, int index) {
    if (!head || index < 0) return NULL;
    link* cur = head;
    for (int i = 0; i < index && cur; ++i) {
        cur = cur->next;
    }
    return cur; /* may be NULL if out of range */
}

/* 1) Remove a node at the given index */
void remove_at(link* head, int index) {
    link* cur = node_at(head, index);
    if (!cur) return;

    if (!cur->prev) {
        /* cur is the head node. We cannot update head externally since we don't have link**.
           If there is a next node – copy its data into the head and remove the next.
           If this is a single-node list – we cannot remove it with this function signature. */
        if (cur->next) {
            link* nxt = cur->next;
            cur->data = nxt->data;
            cur->next = nxt->next;
            if (nxt->next) nxt->next->prev = cur;
            free(nxt);
        }
        else {
            /* Single node list – cannot remove without link** to update head. */
        }
    }
    else {
        /* Internal or last node */
        link* prev = cur->prev;
        link* next = cur->next;
        prev->next = next;
        if (next) next->prev = prev;
        free(cur);
    }
}

/* 2) Detect a cycle – Floyd's algorithm (tortoise and hare).
   Returns a pointer to a node inside the cycle if it exists, otherwise NULL. */
link* circle_exists(link* head) {
    link* slow = head;
    link* fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return slow; /* meeting point inside the cycle */
        }
    }
    return NULL;
}

/* 3) Size of the cycle – if no cycle returns 0 */
int size_of_circle(link* head) {
    link* meet = circle_exists(head);
    if (!meet) return 0;

    int count = 1;
    link* p = meet->next;
    while (p != meet) {
        ++count;
        p = p->next;
    }
    return count;
}
