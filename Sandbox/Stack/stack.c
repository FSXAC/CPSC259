/////////////////////////////Stack implementation using array

#include <stdio.h>
#include <stdlib.h>  /* for dynamic allocation */
#include "stack.h"

#define TRUE 1
#define FALSE 0

void initialize(Stack* stack) {
	stack->top=0;
	stack->list = (int*)malloc(sizeof(int) * CAPACITY);
}


int isFull(Stack* stack) {
    if (stack->top  == CAPACITY-1) return TRUE;
    else return FALSE;
}

int isEmpty(Stack* stack) {
    if (stack->top ==-1) return TRUE;
    else return FALSE;
}

int push(Stack* stack, int value) {
    if (!isFull(stack)) {
        stack->top++;
        stack->list[stack->top]=value;

        return TRUE;
    } else return FALSE;
}



int peek(Stack* stack) {
    if (!isEmpty(stack)) return stack->list[stack->top];
    else return FALSE;
}


int pop(Stack* stack) {
    if (!isEmpty(stack)) {
        stack->list[stack->top]=0;
        stack->top--;
        return TRUE;
    } else return FALSE;
}
