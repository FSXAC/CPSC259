/* Queues - FIFO
 * Enqueue - add element to the end of the queue
 * Dequeue - remove the first element from the head of the queue
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_HOLD 10

// queue
typedef struct {
  int front;
  int back;
  int *list;
} Queue;

// to initialize the queue
Queue * createQueue() {
  Queue *newQueue = (Queue *)malloc(sizeof(Queue));
  newQueue->front = 0;
  newQueue->back  = 0;
  newQueue->list  = (int *)malloc(sizeof(int) * MAX_HOLD);
  return newQueue;
}

// check if queue is emptty
int isEmpty(Queue *q) {
  return (q->front == q->back);
}

int isFull(Queue *q) {
  return (q->front == (q->back + 1) % MAX_HOLD);
}

// enqueue - add element to the end of the queue, shift the back variable by 1
void enqueue(Queue *q, int value) {
  // check if the queue is full
  if (isFull(q)) return;

  // enqueueueue and incrememnt pointer (if at end, move to beginning)
  q->list[q->back] = value;
  if (++(q->back) == MAX_HOLD) q->back = 0;
}

// Dequeue - remove the first element from the head of the queue, shift front variable by 1
int dequeue(Queue *q) {
  // check if it's empty first
  if (isEmpty(q)) return 0;

  int data = q->list[q->front];

  // dequeue and increment front pointer
  if (++(q->front) == MAX_HOLD) q->front = 0;
  return data;
}

void printQueue(Queue *q) {
  if (isEmpty(q)) {
    printf("<empty queue>\n");
    return;
  }

  printf("[");
  for (int i = q->front; i < q->back; i++) {
    printf(" %d,", q->list[i]);
  }

  printf("\b ]\n");
}

int main(void) {
  // array representation of Queues
  // every queue has front and back var that points to th eposition from where deletion and
  // insertion can be done
  Queue *newQ = createQueue();

  // to enqueue
  enqueue(newQ, 4);
  printQueue(newQ);
  enqueue(newQ, 2);
  printQueue(newQ);
  enqueue(newQ, 7);
  printQueue(newQ);
  enqueue(newQ, 16);
  printQueue(newQ);

  // to dequeue
  printf("dequeued: %d\n", dequeue(newQ));
  printQueue(newQ);

  return 0;
}
