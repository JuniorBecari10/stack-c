#include "stack.h"

int main(void) {
    Stack s = new_stack();

    push(&s, 10.2);
    push(&s, 20);
    push(&s, 30);

    pop(&s);
    println(&s);

    Stack copy = clone(&s);
    println(&copy);
    // printf("%s\n", equal(&s, &copy) ? "true" : "false");

    add_all(&s, &copy); 
    println(&s);

    free_stack(&s);
    free_stack(&copy);

    return 0;
}

