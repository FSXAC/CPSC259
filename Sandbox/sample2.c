#include <stdio.h>
#include <stdlib.h>

// Q1
// #define NUM 777
// int main(void) {
//   int x = 10;
//   int *p = NUM;  // cannot assign integer to address
//   int *q = NULL;
//
//   *p = x;
//   x  = *q;
//   &x = NUM;      // cannot assign integer to address
// }


// Q2
// int * makeArray(int n) {
//   int  a[MAXLEN];
//   int  i;
//
//   for (i = 0; i <= MAXLEN; i++) // XXX index will go out of bound
//     a[i] = 0;
//   if (n >= 0  &&  n <= MAXLEN)  // XXX index will go out of bound
//     return a + n;
//
//   return NULL;
// }


// Q3
void new_dynamic_array() {
  int *array = (int *)malloc(sizeof(int) * 100);
  for (int i = 0; i < 100; i++) array[i] = 100;
}

// Q4
struct node {
  int    value;
  struct node *next;
};

int length(struct node *start) {
  if (!start) return 0;
  return 1 + length(start->next);
}

// Q5 - doubly linked list
struct node {
  int item;
  struct node *next;
  struct node *prev;
};

struct * concat(struct node *list1, struct node *list2) {
  // check for conditions
  if (!list1 && !list2) return NULL;
  else if (!list1) return list2;
  else if (!list2) return list1;

  // both lists are valid
  // navigate to the end of the first list
  struct node *current = list1;
  while (!current->next) current = current->next;

  // connect the two together
  current->next = list2;
  list2->prev   = current;

  return list1;
}

// Q6
// single linked list is fine as long as there is a pointer for the last element

// Q7
