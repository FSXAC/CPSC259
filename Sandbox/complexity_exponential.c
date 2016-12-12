#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int      n;
	int      counter = 0;
	double   k;

	printf("Exponential complexity example: 2^n\n");
	printf("Enter a value for n (e.g., 25, 26, or 27): ");
	scanf("%d", &n);

	k = 0.0;
	while (k++ < pow(2.0, n)) counter++;

	printf("The counter is: %d\n", counter);
	return 0;
}
