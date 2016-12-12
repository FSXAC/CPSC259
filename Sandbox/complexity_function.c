#include <stdio.h>
#include <stdlib.h>

void extraFunction(int* counter, int n);

int main(void) {
	int i, j, n;
  int* counter = (int*)malloc(sizeof(int));
  *counter = 0;

	printf("Enter a value for n (e.g., 700, 1000): ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j *= 2)
      extraFunction(counter, n);


	printf("The counter is: %d\n", *counter);
	return 0;
}

void extraFunction(int* counter, int n) {
  for (int i = 0; i < n; i++)
    (*counter)++;
}
