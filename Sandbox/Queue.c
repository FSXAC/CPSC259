/* Queues - FIFO
 * Enqueue - add element to the end of the queue
 * Dequeue - remove the first element from the head of the queue
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_HOLD 10

// TODO: add implementation of CIRCULAR ARRAYS

// queue
typedef struct {
  int front;
  int back;
  int * list;
} Queue;

// to initialize the queue
void qinit(Queue * q) {
  q->front = 0;
  q->back = 0;
  q->list = (int * ) malloc(sizeof(int) * MAX_HOLD);
}

int main(void) {
  // array representation of Queues
  // every queue has front and back var that points to th eposition from where deletion and
  // insertion can be done
  Queue * newQ = NULL;
  qinit(newQ);

  // to enqueue
  enqueue(newQ, 4);

  // to dequeue
  dequeue(newQ);

  return 0;
}

// check if queue is emptty
int isQEmpty(Queue * q) {
  return (q->front == q->back);
}

int isFull(Queue * q) {
  return (MAX_HOLD % (q->back - q->front) == 0);
}

// enqueue - add element to the end of the queue, shift the back variable by 1
int enqueue(Queue * q, int value) {
  // check if the queue is full
  if (!isFull(q)) {
    q->list[q->back++] = value;
    return 1;
  } else return 0;
}

// Dequeue - remove the first element from the head of the queue, shift front variable by 1
int dequeue(Queue * q) {
  // check if the queue is empty
  if (isEmpty(q));
}

// Queues using linked list
// the START pointer of the linked list is used as FRONT
// REAR stroes the address of the last element in the queue
// All insertions are done at rear, all deletions done at FRONT
// if FRONT == REAR ==> NULL, empty queue
