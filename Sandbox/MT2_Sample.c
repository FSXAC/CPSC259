#include <stdio.h>
#include <stdlib.h>

int main(void) {
  return 0;
}

// ex1, compute product of two terms with only addition
int multiply(int m, int n) {
  if (!n) return 0;
  return m + multiply(m, n - 1);
}

int multiply_2(int m, int n) {
  if (n == 1) return m; // more efficient (saves 1 recursion)
  return m + multiply_2(m, n - 1);
}

// ex2, rewrite to tail recusion
// adds number from 1 to a given number
int sum(int num) {
  if (num == 0) return 0;
  return sum(num - 1) + 1;
}

int sum_recursive(int num, int i) {
  if (i <= 0) return num;
  return sum_recursive(num + i, i - 1);
}

// ex3, count how many nodes in a binary tree given struct
struct node {
  int value;
  struct node *left;
  struct node *right;
};

int count(struct node *root) {
  int nodes = 1;

  // check roots
  if (root == NULL) return 0;

  // base cases
  if (root->left == NULL || root->right == NULL) return 1;
  else {
    if (root->left  != NULL) nodes += count(root->left);
    if (root->right != NULL) nodes += count(root->right);
  }

  return nodes;
}

int count_2(struct node *root) {
  // more elegant solution
  if (root == NULL) return 0;
  return 1 + count_2(root->left) + count(root->right);
}

// ex4, drawn on paper

// ex5, find length of linked list given node is
struct node_ll {
  int value;
  struct node_ll *next;
};

int length(struct node_ll *head) {
  int nodes = 0;
  struct node_ll *current = head;

  while (current != NULL) {
    nodes++;
    current = current->next;
  }

  return nodes;
}

int length_recursive(struct node_ll *head, int index) {
  if (head == NULL) return index;
  else return length_recursive(head->next, index + 1);
}

// ex6, concat two linked lists together by changing pointers only
struct node_ll * concat(struct node_ll *list1, struct node_ll *list2) {
  struct node_ll *current = list1;
  struct node_ll *new_list;

  // if both are empty
  if (list1 == NULL && list2 == NULL) return NULL;

  // if list1 is empty
  if (list2 == NULL) return list2;

  // if list2 is empty
  if (list2 == NULL) return list1;

  while (current->next != NULL) current = current->next;
  current->next = list2;
  return new_list;
}

// ex7, drawn on paper
