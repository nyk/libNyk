#include "stack.h"
#include <stdio.h>

nyk_stack* nyk_stack_make(size_t stack_length, size_t item_size) {
    nyk_stack* stack = malloc(sizeof(nyk_stack));
    void* stack_array = malloc(item_size * stack_length);
    fprintf(stderr, "create: typesize=%d, capacity=%d, stack_array: %d\n", 
    (int)item_size, (int)stack_length, (int)sizeof(stack_array));

    stack->items = stack_array;
    stack->length = stack_length;
    stack->top = NYK_STACK_EMPTY;

    return stack;
}

size_t nyk_stack_push(nyk_stack* stack, void* item) {
    stack->top++;
        fprintf(stderr, "stack top: %d, stack_length: %d, input item: %d\n", (int)stack->top, (int)stack->length, *(int*)item);

    if (stack->top < stack->length) {
        stack->items[stack->top] = item;
    }

    fprintf(stderr, "item: %d\n", *(int*)stack->items[stack->top]);
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
    stack->items = NULL;
    free(stack->items);

    stack = NULL;
    free(stack);
    
    return true;
}