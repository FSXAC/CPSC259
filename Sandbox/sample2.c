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

// Q5
