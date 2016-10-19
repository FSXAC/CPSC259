#include <stdio.h>
#include <stdlib.h>

/*
Abstraction of linked array
[5| ]-->[4| ]-->[3|N]
N is for null, when the elements front / end of the list have nowhere to "link"

Doubly linked array
[N|5| ]<->[ |4| ]<->[ |3|N]
*/

// declaring the struct for node
typedef struct node {
  int value;
  struct node * next_node;
} node_t;

// doubly linked list node
typedef struct nodeD {
  int value;
  struct nodeD * prev_node;
  struct nodeD * next_node;
} node_d;

int main(void) {
  // demonstration of linked
  // creating the head of linked list
  node_t * head = malloc(sizeof(node_t)); // create memory
  head->value = 1;                        // values inside the list
  head->next_node = NULL;

  // alternative head, instead of being a pointer, the head is an instance
  node_t head_alt = {1, NULL};

  return 0;
}

// add element to the end of another node
void addElement(node_t * head, int next_value, node_t * tail) {
  head->next_node = malloc(sizeof(node_t));
  head->next_node->value = next_value;
  head->next_node->next_node = tail;
}

// a more intuitive way to add element to the end of the node
void addElementAtEnd(node_t head, int next_value) {
  // go to the end of the linked list
  node_t * current = head;
  while (current->next != NULL) {
    current = current->next;
  }

  // now add one at the end
  current->next_node = malloc(sizeof(node_t));
  current->next_node->value = next_value;
  current->next_node->next_node = NULL;
}

// // add element in front of a node
// node_t addElementAsHead(node_t * head, int next_value) {
//   node_t new_node = malloc(sizeof(node_t));
//   new_node->value = next_value;
//   new_node->next_node = head;
//
//   // this becomes the new head
//   return new_node
// }

// add element in front of a node (no return)
void addElementAsHead(node_t * head, int next_value) {
  node_t new_node = malloc(sizeof(node_t));
  new_node->value = next_value;
  new_node->next_node = head;
  head = new_node;
}

// insert element at a specific location (after index)
void insertElement(node_t * head, int next_value, int index) {
  int i = 0;
  node_t * current = head;
  node_t new_node = malloc(sizeof(node_t));


  // go to the the location
  for (i = 0; i < index; i++) {
    current = current->next_node;
  }

  // initalize new node
  new_node->value = next_value;
  new_node->next_node = current->next_node;
  current->next_node = new_node;
}

// remove an element from a list
void removeElement(node_t * head, int index) {
  int i = 0;
  node_t * current = head;
  node_t * previous;

  for (i = 0; i < index; i++) {
    previous = current;
    current = current->next_node;
  }

  // skip the one to delete (current)
  previous->next_node = current->next_node;

  // free up memory
  free(current);

  // no dangling pointers
  current = NULL;
}

// remove an element from a doubly linked list
void removeElementD(node_d * head, int index) {
  int i = 0;
  node_d * current = head;

  for (i = 0; i < index; i++) {
    current = current->next_node;
  }

  current->prev_node->next_node = current->next_node;
  current->next_node->prev_node = current->prev_node;
  free(current);
  current = NULL;
}

// display linked list
void displayList(node_t * head) {

  // create a variable to iterate
  node_t * current = head;

  while (head != NULL) {
    printf("%d\n", current->value);

    // follow the link
    current = current->next_node;
  }
}
