#include <stdio.h>
#include <stdlib.h>
#include "memory.h"
#include "strings.h"
#include "linkedlist.h"

/* Helper: create a new node (returns NULL on failure) */
static link* make_node(int value) {
    link* n = (link*)malloc(sizeof(link));
    if (!n) return NULL;
    n->data = value;
    n->next = NULL;
    n->prev = NULL;
    return n;
}

int main(void) {
    /* =======================
       A) memory (my_realloc)
       ======================= */
    printf("=== memory tests ===\n");

    int* arr = (int*)malloc(3 * sizeof(int));
    if (!arr) { printf("malloc failed\n"); return 1; }

    arr[0] = 1; arr[1] = 2; arr[2] = 3;

    arr = (int*)my_realloc(arr, 3 * sizeof(int), 5 * sizeof(int));
    if (!arr) { printf("my_realloc failed (expand)\n"); return 1; }

    arr[3] = 4; arr[4] = 5;
    for (int i = 0; i < 5; ++i) printf("%d ", arr[i]);
    puts("");

    arr = (int*)my_realloc(arr, 5 * sizeof(int), 2 * sizeof(int));
    if (!arr) { printf("my_realloc failed (shrink)\n"); return 1; }

    for (int i = 0; i < 2; ++i) printf("%d ", arr[i]);
    puts("");

    arr = (int*)my_realloc(arr, 2 * sizeof(int), 0);
    printf("arr == NULL ? %s\n\n", arr == NULL ? "yes" : "no");

    /* =======================
       B) strings
       ======================= */
    printf("=== strings tests ===\n");

    char* t = my_strcpy("abacad", 'a');
    if (!t) { printf("my_strcpy failed\n"); return 1; }
    printf("my_strcpy(\"abacad\", 'a') -> %s\n", t);
    free(t);

    const char blob[] = "hello\0world\0C\0";
    printf("n_words(3, blob):\n");
    n_words(3, blob);
    puts("");

    /* =======================
       C) linked list
       ======================= */
    printf("=== linked list tests ===\n");

    /* Build list: 10 <-> 20 <-> 30 */
    link* a = make_node(10);
    link* b = make_node(20);
    link* c = make_node(30);
    if (!a || !b || !c) {
        printf("make_node failed\n");
        free(a); free(b); free(c);
        return 1;
    }
    a->next = b; b->prev = a;
    b->next = c; c->prev = b;

    printf("Before remove_at: %d %d %d\n",
        a->data, a->next->data, a->next->next->data);

    remove_at(a, 1); /* remove node at index 1 (value 20) */

    if (a && a->next) {
        printf("After remove_at: %d %d\n", a->data, a->next->data);
    }
    else {
        printf("After remove_at: list too short\n");
    }

    /* Create a cycle: c->next = a, a->prev = c */
    c->next = a;
    a->prev = c;

    link* cycle_node = circle_exists(a);
    printf("circle_exists -> %s\n", cycle_node ? "found" : "none");
    printf("size_of_circle -> %d\n", size_of_circle(a));

    /* Note: there is a cycle now; we intentionally do not free nodes in this demo. */
    return 0;
}
