
#ifndef _STACK_H
#define _STACK_H

static const int CAPACITY = 200;


/*
 * This is the type for a stack, i.e., it is a type that
 * holds the information necessary to keep track of a stack.
 * It has an array (used to hold the contents of the stack), an integer
 * `CAPACITY' that holds the size of this array (i.e., the
 * maximum number of things that can be held in the stack),
 * and another integer `top,' which stores the array index of
 * the element at the top of the stack.
 */

typedef struct
{
    int top;
    int* list;
} Stack;

/*
 * States whether the stack is full or not
 * PARAM:     Stack*     --  a pointer to the stack
 *
 * RETURN:    1 if the stack is full and 0 otherwise
 */
int isFull(Stack* stack);


/*
 * States whether the stack is empty or not
 * PARAM:     Stack*     --  a pointer to the stack
 *
 * RETURN:    1 if the stack is empty and 0 otherwise
 */
int isEmpty(Stack* stack);


/*
 * Adds a new item to the stack
 * PARAM:     Stack*     --  a pointer to the stack
 * PARAM:     int        --  the int to be added
 *
 * RETURN:    1 if the item was successfully added and 0 otherwise
 */
int push(Stack* stack, int value);



/*
 * to initialize the stack
 * PARAM:     Stack*     --  a pointer to the stack
 *
 */

void initialize(Stack* stack);




/*
 * returns the current top of the stack
 * PARAM:     Stack*     --  a pointer to the stack
 *
 * RETURN:    the value on top of stack and -1 if it is empty
 */
int peek(Stack* stack);


/*
 * removes an item from the top of the stack
 * PARAM:     Stack*     --  a pointer to the stack
 *
 * RETURN:    1 if the item was successfully removes and 0 otherwise
 */
int pop(Stack* stack);


#endif  /* not defined _STACK_H */
