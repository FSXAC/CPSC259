/* example of complexity:  exponential loop

   I made a small change over complexity2.c:  Here, the pow(2.0, n)
   call is issued just once ... before the WHILE loop.  This allows us
   to do MANY more computations in the same amount of time (e.g., n=26
   in version 2 can grow to n=29 here, for about the same CPU cost). */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int      n;
	int      counter = 0;
	double   k, limit;

	printf("Exponential complexity example: 2^n.\n");
	printf("Enter a value for n (e.g., 29, 30, or 31): ");
	scanf("%d", &n);

	k = 0.0;
	limit = pow(2.0, n);
	while (k++ < limit) counter++;

	printf("The counter is: %d\n", counter);
	return 0;
}
