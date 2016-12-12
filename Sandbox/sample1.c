#include <stdlib.h>
#include <stdio.h>

// Q1
// A

// Q2
// O(1/n), O(n^1/3), O(n^1/2), O(lg n), O(n)

// Q3
// j is O(lg N)
// outer: O(N), inner: O(j * N) === O(N lgN)
// ->O(N^2lgN)

// Q4
struct Node {
  char * name;
  struct Node * prev;
  struct Node * next;
};

int printNodesinOneDirection(struct Node * curr, char LeftOrRight) {

  // POST-CONDITION: This function starts at Node “curr” and then prints out
  // all the names in the nodes to the left (‘L’) or right (‘R’) of curr (but
  // excluding the name in curr.  The function returns a count of the number
  // of names printed on the screen.
  // PRE-CONDITION: curr is either NULL or points to a valid Node shown above
  //                LeftOrRight is either ‘L’ or ‘R’

  /* Declare any needed variables here.  Follow this with your code. (Some code is provided further below.) */
  int count = 0;

  // check if empty list
  if (curr == NULL) return 0;

  if (LeftOrRight == 'L') {
    printf("%s\n", curr->name);

    // base condition - stop going left
    if (curr->prev == NULL) return 1;

    // recursivly go left
    count += printNodesinOneDirection(curr->prev, LeftOrRight);
  } else {
    // to the right
    printf("%s\n", curr->name);

    // base condition - stop going right
    if (curr->next == NULL) return 1;
    count += printNodesinOneDirection(curr->next, LeftOrRight);
  }

  return count;
}

// Q5
// A
// CHANGED B

// Q6
// A

// Q7
// B

// Q8
int main(void) {
  int x = 5;
  int y = 15;
  int *p1, *p2;

  p1  = &x;     // x contains 5; y contains 15
  p2  = &y;     // x contains 5; y contains 15
  *p1 = 10;     // x contains 10; y contains 15
  *p2 = *p1;    // x contains 10; y contains 10
  p1  = p2;     // x contains 10; y contains 10
  *p1 = *p2+10; // x contains 10; y contains 20

  return 0;
}

// Q9
void merge(int a[], int n1, int b[], int n2, int c[] ) {
  // merge ordered list a and b into c (also ordered)
  // n1 length of a, n2 length of b
  int a_index = 0;
  int b_index = 0;
  // int total   = n1 + n2;
  int i       = 0;

  // int a_valid;
  // int b_valid;
  // int a_larger;
  //
  // for (; i < total; i++) {
  //   a_valid  = a_index < n1;
  //   b_valid  = b_index < n2;
  //   a_larger = a[a_index] < b[b_index];
  //
  //   if (a_valid && b_valid) {
  //     // copy from the smallest
  //     c[i] = a_larger ? a[a_index++] : b[b_index++];
  //   } else if (a_valid && !b_valid) {
  //     c[i] = a[a_index++];
  //   } else {
  //     c[i] = b[b_index++];
  //   }
  // }

  // pick the minimum from both sides
  while (a_index < n1 && b_index < n2)
    c[i++] = (a[a_index] < b[b_index]) ? a[a_index++] : b[b_index++];

  // pick from the rest
  while (a_index < n1) c[i++] = a[a_index++];
  while (b_index < n2) c[i++] = b[b_index++];
}
