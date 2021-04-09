#include "gtest/gtest.h"

extern "C" {
  #include "datastructures/stack/stack.h"
}

TEST(StackTest, StackMake) {
  nyk_stack* stack = nyk_stack_make(10, sizeof(int*));
  EXPECT_EQ(stack->top, NYK_STACK_EMPTY);
  EXPECT_EQ(stack->length, 10);
  nyk_stack_destroy(stack);
}

TEST(StackTest, StackPush) {
  nyk_stack* stack = nyk_stack_make(3, sizeof(int*));
  EXPECT_EQ(stack->length, 3);
  EXPECT_EQ(stack->top, NYK_STACK_EMPTY);

  int a, b, c, d;
  signed long rv = nyk_stack_push(stack, &(a = 6));
  EXPECT_EQ(rv, stack->top);
  EXPECT_EQ(stack->top, 0);
  EXPECT_EQ(*(int*)stack->items[stack->top], a);

  nyk_stack_push(stack, &(b = 8));
  EXPECT_EQ(stack->top, 1);
  EXPECT_EQ(*(int*)stack->items[stack->top], b);

  nyk_stack_push(stack, &(c = 4));
  EXPECT_EQ(stack->top, 2);

   nyk_stack_destroy(stack);
}

TEST(StackTest, StackPopOptimism) {
  nyk_stack* stack = nyk_stack_make(4, sizeof(int*));

  // Initialize stack array
  int a, b, c, d;
  nyk_stack_push(stack, &(a = 1));
  nyk_stack_push(stack, &(b = 2));
  nyk_stack_push(stack, &(c = 3));
  nyk_stack_push(stack, &(d = 4));

  int out;
  out = *(int*)nyk_stack_pop(stack);
  EXPECT_EQ(out, 4);
  EXPECT_EQ(stack->top, 2);

  out = *(int*)nyk_stack_pop(stack);
  EXPECT_EQ(out, 3);
  EXPECT_EQ(stack->top, 1);
  
  nyk_stack_push(stack, &(c = 3));
  EXPECT_EQ(stack->top, 2);

  out = *(int*)nyk_stack_pop(stack);
  EXPECT_EQ(out, 3);
  EXPECT_EQ(stack->top, 1);

  nyk_stack_destroy(stack);
}