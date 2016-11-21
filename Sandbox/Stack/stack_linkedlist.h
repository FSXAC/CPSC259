/*  stack_linkedlist.h  CPSC 259 */


#ifndef CPSC_259_stack_linkedlist_h
#define CPSC_259_stack_linkedlist_h


struct Node
{
    int data;
    struct Node* next;
};


typedef struct{
    struct Node* top;
} Stack_list;






/*
 * States whether the stack is empty or not
 * PARAM:     Stack*     --  a pointer to the stack
 *
 * RETURN:    1 if the stack is empty and 0 otherwise
 */
int isEmpty_list(Stack_list* stack);


/*
 * Adds a new item to the stack
 * PARAM:     Stack*     --  a pointer to the stack
 * PARAM:     int        --  the int to be added
 *
 * RETURN:    1 if the item was successfully added and 0 otherwise
 */
int push_list(Stack_list* stack, int value);


/*
 * returns the current top of the stack
 * PARAM:     Stack*     --  a pointer to the stack
 *
 * RETURN:    the value on top of stack and -1 if it is empty
 */
int peek_list(Stack_list* stack);


/*
 * removes an item from the top of the stack
 * PARAM:     Stack*     --  a pointer to the stack
 *
 * RETURN:    1 if the item was successfully removes and 0 otherwise
 */
int pop_list(Stack_list* stack);


#endif
