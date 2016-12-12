// stack using linked lists
// using top pointer of the stack

#include <stdio.h>
#include <stdlib.h>

// defining node struct
struct Node {
  int data;
  struct Node *next;
};

// main linked list that contains the top pointer
typedef struct {
  struct Node *top;
} Stacklist;

// function for creating linked list
Stacklist * createStack() {
  Stacklist *newStack =(Stacklist *)malloc(sizeof(Stacklist));
  newStack->top = NULL;
  return newStack;
}

// check if the list is empty - check if top is NULL
int isEmpty(Stacklist *list) {
  return (list->top == NULL) ? 1 : 0;
}

// pushing an item into the stack
void push(Stacklist *stack, int value) {
  struct Node * newNode = (struct Node*)malloc(sizeof(struct Node));

  // if failed to allocate memory:
  if (!newNode) return;

  // setup new node and add it into stack
  newNode->data = value;
  newNode->next = stack->top;
  stack->top    = newNode;
}

// poping an item from the stack
int pop(Stacklist *stack) {
  // check if the list is empty first
  if (!isEmpty(stack)) {
    struct Node *temp;
    int data;

    // we only have to free the temp as top already points to the next item
    temp       = stack->top;
    data       = temp->data;
    stack->top = stack->top->next;

    free(temp);
    temp = NULL;
    return data;
  }

  return 0;
}

// peeking
int peek(Stacklist *stack) {
  return (isEmpty(stack)) ? 0 : stack->top->data;
}
