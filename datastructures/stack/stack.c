#include "stack.h"
#include <stdio.h>

typedef struct nsp {
    size_t length;
    size_t top;
    void** items;
} nyk_stack;

nyk_stack* nyk_stack_make(size_t stack_length, size_t item_size) {
    nyk_stack* stack = malloc(sizeof(nyk_stack));
    void* stack_array = malloc(item_size * stack_length);

    stack->items = stack_array;
    stack->length = stack_length;
    stack->top = NYK_STACK_EMPTY;

    return stack;
}

bool nyk_stack_chk_pos(nyk_stack* stack, size_t val) {
    return (stack->top == val);
}

bool nyk_stack_chk_cap(nyk_stack* stack, size_t val) {
    return (stack->length = val);
}

size_t nyk_stack_top(nyk_stack* stack) {
    return stack->top;
}

void* nyk_stack_item(nyk_stack* stack, size_t index ) {
    return stack->items[index];
}

size_t nyk_stack_push(nyk_stack* stack, void* item) {
    stack->top++;

    if (stack->top < stack->length) {
        stack->items[stack->top] = item;
    }

    return stack->top;
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
    free(stack->items);
    stack->items = NULL;

    free(stack);
    stack = NULL;

    return true;
}