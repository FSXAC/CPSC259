/*  stack_linkedlist.h  CPSC 259 */

#include <stdio.h>
#include <stdlib.h>
#include "stack_linkedlist.h"

#define TRUE 1
#define FALSE 0


int isEmpty_list( Stack_list* stack) {
  if (stack->top == NULL) return TRUE;
  else return FALSE;
}



int push_list( Stack_list* stack, int value) {
  struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
  new_node->data = value;
  new_node->next = stack->top;
  stack->top = new_node;
  return 1;
}

int peek_list(Stack_list* stack) {
  if (!isEmpty_list(stack)) {
      return stack->top->data;
      return TRUE;
  } else return FALSE;
}

int pop_list(Stack_list* stack) {
  if (!isEmpty_list(stack)) {
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    temp = NULL;
    return TRUE;
  }
  return FALSE;
}
