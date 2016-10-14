#include <stdio.h>
#include <stdlib.h>

/*
Abstraction of linked array
[N|5| ]<->[ |4| ]<->[ |3|N]
N is for null, when the elements front / end of the list have nowhere to "link"
*/

// declaring the struct for node
typedef struct node {
  int value;
  struct node * next_node;
} node_t;

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

// add element in front of a node
node_t addElementAsHead(node_t * head, int next_value) {
  node_t new_node = malloc(sizeof(node_t));
  new_node->value = next_value;
  new_node->next_node = head;

  // this becomes the new head
  return new_node
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
