// Priority Queues in C using binary heap
//
// - A BAG of items - (set has no duplicates, bag does)
// - follows the heap property
//
// Array mapping:
// left child  = 2 * node + 1
// right child = 2 * node + 2
// parent      = floor((node - 1) / 2)
// nextfree    = length
// root        = 0

// Maximum binary heap: parent >= child (largest on top)
// Minimum binary heap: child >= parent (smallest on top)
//
// basic operations for priority queue:
// push   : add an element with priority into the queue
// pop    : deal with the top element
// isEmpty:
//
// internal operations:
// siftUp : swap values with (larger / smaller) child when node
//          does not have heap property
// create : for creating a priority queue from array
// destroy: for destroying ...

#include <stdio.h>
/* swap two numbers */
void swap(int *a, int *b) {
  int temp = *a;
  *a       = *b;
  *b       = temp;
}

/* fix heap property */
void siftUp(int *data, int top, int bottom) {
  if (bottom > top) {
    int parent = getparent(bottom);
    if (data[parent] < data[bottom]) {
      swap(&data[parent], &data[bottom]);
      siftUp(data, top, parent);
    }
  }
}
