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

#ifndef _NYK_STACK
#define _NYK_STACK
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief value indicating an empty stack
 * 
 */
#define NYK_STACK_EMPTY (-1)

/**
 * @brief 
 * 
 */
typedef struct {
    size_t length;
    size_t top;
    void** items;
} nyk_stack;

/**
 * @brief constructor to make a new stack object
 * 
 * @param stack_length the size or capacity of the stack
 * @param item_size the size of each item
 * @return nyk_stack a new stack object
 */
nyk_stack* nyk_stack_make(size_t stack_length, size_t item_size);

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

#endif // _NYK_STACK