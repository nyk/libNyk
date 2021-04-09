#include "gtest/gtest.h"

extern "C" {
  #include "datastructures/stack/stack.h"
}

TEST(StackTest, StackMake) {
  size_t capacity = 10;
  nyk_stack* stack = nyk_stack_make(capacity, sizeof(int*));
  EXPECT_TRUE(nyk_stack_chk_pos(stack, NYK_STACK_EMPTY));
  EXPECT_TRUE(nyk_stack_chk_cap(stack, capacity));
  nyk_stack_destroy(stack);
}


TEST(StackTest, StackPushOptimist) {
  size_t capacity = 3;
  nyk_stack* stack = nyk_stack_make(3, sizeof(int*));
  EXPECT_TRUE(nyk_stack_chk_cap(stack, capacity));
  EXPECT_TRUE(nyk_stack_chk_pos(stack, NYK_STACK_EMPTY));

  int a, b, c, d;
  EXPECT_TRUE(nyk_stack_push(stack, &(a = 6)));
  EXPECT_TRUE(nyk_stack_chk_pos(stack, 0));

  size_t idx = nyk_stack_top(stack);
  int item = *(int*)nyk_stack_item(stack, idx);
  EXPECT_EQ(item, a);

  nyk_stack_push(stack, &(b = 8));
  idx = nyk_stack_top(stack);
  item = *(int*)nyk_stack_item(stack, idx);
  EXPECT_EQ(item, b);

  nyk_stack_push(stack, &(c = 8));
  idx = nyk_stack_top(stack);
  item = *(int*)nyk_stack_item(stack, idx);
  EXPECT_EQ(item, c);

  nyk_stack_destroy(stack);
}

TEST(StackTest, StackPushPessimist) {
  int a, b, c;
  nyk_stack* stack = nyk_stack_make(2, sizeof(int*));
  EXPECT_TRUE(nyk_stack_push(stack, &(a = 1)));
  EXPECT_TRUE(nyk_stack_push(stack, &(b = 2)));
  EXPECT_FALSE(nyk_stack_push(stack, &(c = 3)));
  nyk_stack_destroy(stack);
}

TEST(StackTest, StackPopOptimist) {
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
  EXPECT_EQ(nyk_stack_top(stack), 2);

  out = *(int*)nyk_stack_pop(stack);
  EXPECT_EQ(out, 3);
  EXPECT_EQ(nyk_stack_top(stack), 1);
  
  nyk_stack_push(stack, &(c = 3));
  EXPECT_EQ(nyk_stack_top(stack), 2);

  out = *(int*)nyk_stack_pop(stack);
  EXPECT_EQ(out, 3);
  EXPECT_EQ(nyk_stack_top(stack), 1);

  nyk_stack_destroy(stack);
}

TEST(StackTest, StackPopPessimist) {
  int a;
  nyk_stack* stack = nyk_stack_make(1, sizeof(int*));
  nyk_stack_push(stack, &(a = 1));
  EXPECT_TRUE(*(int*)nyk_stack_pop(stack), 1);
  EXPECT_FALSE((int*)nyk_stack_pop(stack));
}