#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int * i;

	/* dynamic allocation of an array of 10 integers */
	i = (int *) malloc(10 * sizeof(int));


	if (!i) {
		printf("Error: can't get memory ...\n");
	  return -1;
	}

	/* Two ways to access the array:
  (1) regular APSC 160 way of using an array
  (2) via pointer arithmetic */
	printf("Address of i[0] is: %d\n", &i[0]);
	printf("Address of i[1] is: %d\n", &i[1]);
	printf("Address of i[2] is: %d\n", &i[2]);

	printf("address of the start of the array is %d\n", i);
	printf("address of *(i + 0) is %d\n", (i + 0));  /* same as &*(i+0) */
	printf("address of *(i + 1) is %d\n", (i + 1));
	printf("address of *(i + 2) is %d\n", (i + 2));

	/* Two ways to access the array, cont. */
	i[0] = 3;
	*(i + 0) *= 2;

	*(i + 1) = 16;
	i[1] *= 2;

	/* Two ways, cont. */
	printf("The content of i[0] is %d\n", i[0]);
	printf("The content of (i + 1) is %d\n", *(i + 1));
  free(i);
  i = NULL;
	return 0;
}
