#include "stack.h"

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#define INITIAL_CAP 10
#define GROW_FACTOR 2

Stack new_stack() {
    return (Stack) {
        .list = NULL,
        .len = 0,
        .cap = 0,
    };
}

void free_stack(Stack *s) {
    free(s->list);
    s->list = NULL;
}

void push(Stack *s, double e) {
    if (isnan(e)) return;

    if (s->list == NULL) {
        s->list = malloc(INITIAL_CAP * sizeof(double));
        s->cap = INITIAL_CAP;
    }
    
    else if (s->cap < s->len + 1) {
        s->list = realloc(s->list, s->cap * GROW_FACTOR * sizeof(double));
        
        if (s->list == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        
        s->cap *= GROW_FACTOR;
    }

    s->list[s->len++] = e;
}

double pop(Stack *s) {
    if (s->len == 0) return NAN;
    return s->list[--s->len];
}

bool equal(Stack *a, Stack *b) {
    if (a->len != b->len) return false;
    return memcmp(a->list, b->list, a->len * sizeof(double)) == 0;
}

bool is_empty(Stack *s) {
    return s->len == 0;
}

size_t len(Stack *s) {
    return s->len;
}

size_t cap(Stack *s) {
    return s->cap;
}

void println(Stack *s) {
    printf("[");
    
    for (size_t i = 0; i < s->len; i++) {
        printf("%.10g", s->list[i]);
        
        if (i < s->len - 1)
            printf(", ");
    }

    printf("]\n");
}

Stack clone(Stack *s) {
    Stack ret = new_stack();
    add_all(&ret, s);

    return ret;
}

void add_all(Stack *dest, Stack *src) {
    if (dest->cap < dest->len + src->len) {
        dest->list = realloc(dest->list, (dest->len + src->len) * sizeof(double));
        
        if (dest->list == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        
        dest->cap = dest->len + src->len;
    }

    memcpy(dest->list + dest->len, src->list, src->len * sizeof(double));
    dest->len += src->len;
}

void remove_all(Stack *s) {
    free(s->list);
    *s = new_stack();
}

