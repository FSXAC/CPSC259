
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "stack_linkedlist.h"

int main(void) {
  Stack          s;
	Stack_list     sl;
	int i;

  initialize(&s);

  for (i=0; i<100; i++) {
      push(&s, i);
  }

  for (i=0; i<100; i++) {
      printf("%d \n", peek(&s));
      pop(&s);
  }


  for (i=200; i<300; i++) {
      push_list(&sl, i);
  }

  for (i=200; i<300; i++) {
      printf("%d \n", peek_list(&sl));
      pop_list(&sl);
  }

	system("PAUSE");
  return 0;
}
