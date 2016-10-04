// Algorthm Analysis

#include <stdlib.h>
#include <stdio.h>

int main(void) {
    return 1;
}


/* EX: given N numbers, find K'th largest number given K < N */
void ex1() {
    int N1[10] = {
        60, 22, 90, 12, 51, 46, 2, 1, 99, 72
    };

    int N2[10] = {
        60, 22, 90, 12, 51, 46, 2, 1, 99, 72
    };


    /* METHOD ONE
       Sort, then get get k'th*/

    /* METHOD TWO
       read first K elements into the array, read element one by one
       If larger than k'th element, move it into its spot (one is bumped out of the program)*/
}

/* Analyzing algorithms*/
void ex2() {
    // two instructions
    int a = 1, b = 1;

    // another one
    int result;

    for (int i = 0; i < 10; i++) {
        // three instructions * 10 times in the loop
        result = a + b;
        a = b;
        b = result;
    }
}