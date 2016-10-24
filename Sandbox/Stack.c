/*
  ADT - Abstract Data Type - mathematical data type
  Ideal data structure: fast, elegant, memory efficient
  Trade offs: time vs space
              performance vs elegance
              generality vs simplicity
              serial performance vs parallel performance

  ADT describes the design - not the actual implementation/code

  Stacks: abstract ordered data structure

  Operations: create    -  create a stack
              destroy   -  delete entire stack
              push      -  insert to stack
              pop       -  read and remove from stack
              top/peek  -  read only
              is_empty  -  check if stack is empty

  Properties: LIFO - LAST IN FIRST OUT

  ex: Call stack  -  nested function calls uses stack to keep track of nesting
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// maximum number of items a stack can hold
#define MAX_HOLD 10

int main(void) {
  return 0;
}

// Array representation of stack
typedef struct stack{
  // top is the index of the top most element
  int top;
  int * list;
} Stack;

void initialize(Stack * stack) {
  stack->top = -1;

  // creating an array of 10 integers
  stack->list = (int *)malloc(sizeof(int) * 10);
}

int isEmtpy(Stack * stack) {
  // when the index is less than 0
  return (stack->top == -1);
}

int isFull(Stack * stack) {
  // when the index reaches the maximum number a stack can hold
  return (stack->top == MAX_HOLD-1);
}

// push / inserting operation
int push(Stack * stack, int value) {
  // must check if the stack is full or not
  if (!isFull(stack)) {
    // increment top (-1 -> 0)
    stack->top++;
    // add value to stack with list index [top]
    stack->list[stack->top] = value;
    return TRUE;
  } else {
    // exception
    return FALSE;
  }
}

// return the top value, but do not remove
int peek(Stack * stack) {
  if (!isEmpty(stack)) {
    return stack->list[stack->top];
  } else {
    return NULL;
  }
}

int pop(Stack * stack) {
  // create return val
  int popval;

  // must check if the stack is empty
  if (!isEmpty(stack)) {
    popval = peek(stack);

    // move top to the previous down
    stack->top--;
    return popval;
  } else {
    return NULL;
  }
}
