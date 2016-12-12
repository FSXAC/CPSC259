// Queues using linked list
// the START pointer of the linked list is used as FRONT
// REAR stroes the address of the last element in the queue
// All insertions are done at rear, all deletions done at FRONT
// if FRONT == REAR ==> NULL, empty queue

#include <stdio.h>
#include <stdlib.h>

// defining node struct
struct Node {
  int data;
  struct Node *next;
};

// main linked list that contains the top pointer
typedef struct {
  struct Node *front;
  struct Node *rear;
} QList;

// function for creating linked list
QList * createStack() {
  QList *newQueue = (QList *)malloc(sizeof(QList));
  newQueue->front = NULL;
  newQueue->rear  = NULL;
  return newQueue;
}

// check if a queue is empty
int isEmpty(QList *q) {
  return (q->front == q->rear && q->front == NULL);
}

// add an element to the queue
void enqueue(QList *q, int value) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data        = value;
  newNode->next        = q->front;
  q->front             = newNode;
}

// remove an element from the queue from the rear
int dequeue(QList *q) {
  if (isEmpty(q)) return 0;

  int data = q->rear->data;
  // something here

  return 1;
}
