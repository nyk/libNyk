#include "../headers/stack.h"

nyk_stack nyk_stack_make(size_t item_size, size_t stack_length) {
    void* stack_array = malloc(item_size * stack_length);
    nyk_stack stack = {
        .items = &stack_array,
        .length = stack_length,
        .top = NYK_STACK_EMPTY,
    };

    return stack;
}

bool nyk_stack_push(nyk_stack* stack, void* item) {
    stack->top++;

    if (stack->top < stack->length) {
        stack->items[stack->top] = item;
        return true;
    }

    return false;
}

void* nyk_stack_pop(nyk_stack* stack) {
    if (stack->top == NYK_STACK_EMPTY) {
        return NULL;
    }

    void* item = stack->items[stack->top];
    stack->top--;
    return item;
}

bool nyk_stack_destroy(nyk_stack* stack) {
    stack->items = NULL;
    free(stack->items);
    return true;
}