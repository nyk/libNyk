/**
 * @file stack.h
 * @author Nyk Cowham (nyk@cowham.net)
 * @brief A library to implement a simple generic stack container
 * @version 0.1
 * @date 2021-04-04
 * 
 * @copyright Copyright (c) 2021 Nicholas Cowham
 * 
 */

#ifndef NYK_STACK_H
#define NYK_STACK_H

#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief value indicating an empty stack
 * 
 */
#define NYK_STACK_EMPTY (-1)

/**
 * @brief incomplete type returned from nyk_stack_make()
 * 
 */
typedef struct nsp nyk_stack;

/**
 * @brief constructor to construct a new stack handle
 * 
 * @param stack_length the size or capacity of the stack
 * @param item_size the size of each item
 * @return nyk_stack a new stack handle
 */
nyk_stack* nyk_stack_make(size_t stack_length, size_t item_size);

/**
 * @brief add a new item to the top of the stack
 * 
 * @param stack a pointer to a stack object
 * @param item a pointer to a new item to add to the stack
 * @return true if successfully pushed on the stack
 * @return false if item was not pushed on the stack
 */
bool nyk_stack_push(nyk_stack* stack, void* item);

/**
 * @brief take an item off from the top of the stack
 * 
 * @param stack a pointer to the stack object
 * @return void* the next item from the top of the stack
 */
void* nyk_stack_pop(nyk_stack* stack);

/**
 * @brief free pointers stored on the stack before destroying it
 * 
 * @param stack handle to release
 */
void nyk_stack_destroy(nyk_stack* stack);


/* !!! FUNCTIONS FOR USE BY TEST SUITES ONLY !!! */

// * This is here for testing internal state. It is NOT
// * a part of the public API to the stack.
bool nyk_stack_chk_pos(nyk_stack* stack, size_t val);

// * This is here for testing internal state. It is NOT
// * a part of the public API to the stack.
void* nyk_stack_item(nyk_stack* stack, size_t index);

// * This is here for testing internal state. It is NOT
// * a part of the public API to the stack.
size_t nyk_stack_top(nyk_stack* stack);

// * This is here for testing internal state. It is NOT
// * a part of the public API to the stack.
bool nyk_stack_chk_cap(nyk_stack* stack, size_t val);

#endif // NYK_STACK_H