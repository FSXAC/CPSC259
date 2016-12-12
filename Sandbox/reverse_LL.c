#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};

typedef struct {
  struct node *head;
} list;

list * reverseLL(list *head) {
  // check for conditions
  if (!head) return NULL;
  if (!head->next) return head;

  // call the recursive that handles the rest
  struct node *rest = reverseLL(first->next);

  // deal with the first part and make the pointers point to NULL
  head->next->next = head;
  head->next       = NULL;
  return rest;
}
