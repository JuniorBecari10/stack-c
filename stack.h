#ifndef STACK_H
#define STACK_H

#include <stddef.h>
#include <stdbool.h>

typedef struct {
    double *list;
    size_t len;
    size_t cap;
} Stack;

Stack new_stack();
void free_stack(Stack *s);

// cannot be NaN
void push(Stack *s, double e);
// returns NaN if the stack is empty.
double pop(Stack *s);

bool is_empty(Stack *s);
bool equal(Stack *a, Stack *b);

size_t len(Stack *s);
size_t cap(Stack *s);

void println(Stack *s);

Stack clone(Stack *s);

void add_all(Stack *dest, Stack *src);
void remove_all(Stack *s);

#endif // !STACK_H

