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
#include <stdint.h>

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
 * @brief constructor to make a new stack object
 * 
 * @param stack_length the size or capacity of the stack
 * @param item_size the size of each item
 * @return nyk_stack a new stack object
 */
nyk_stack* nyk_stack_make(size_t stack_length, size_t item_size);

/**
 * @brief returns the current position of the stack
 * 
 * This is here for testing internal state.
 * 
 * @param stack a handle to the stack
 * @param val a size_t value to compare with the index of the current stack position
 * @return true if the 
 */
bool nyk_stack_chk_pos(nyk_stack* stack, size_t val);

/**
 * @brief 
 * 
 * @param stack 
 * @param index 
 * @return void* 
 */
void* nyk_stack_item(nyk_stack* stack, size_t index);

/**
 * @brief 
 * 
 * @param stack 
 * @return size_t 
 */
size_t nyk_stack_top(nyk_stack* stack);

/**
 * @brief returns the capacity of the stack
 * 
 * This is mostly here for testing internals
 * 
 * @param stack a handle to the stack
 * @return size_t the capacity of the stack array
 */
bool nyk_stack_chk_cap(nyk_stack* stack, size_t val);

/**
 * @brief add a new item to the top of the stack
 * 
 * @param stack a pointer to a stack object
 * @param item a pointer to a new item to add to the stack
 * @return the index value of the top of the stack array
 */
size_t nyk_stack_push(nyk_stack* stack, void* item);

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
 * @param stack 
 * @return true if the stack was successfully destroyed
 * @return false if the stack was not fully destroyed
 */
bool nyk_stack_destroy(nyk_stack* stack);

#endif // NYK_STACK_H