#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i, j, k, n;
	int counter = 0;

  printf("Cubic complexity example: \n");
	printf("Enter a value for n (e.g., 700, 1000): ");
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			for (k = 1; k <= n; k++)
				counter++;

	printf("The counter is: %d\n", counter);
	return 0;
}
