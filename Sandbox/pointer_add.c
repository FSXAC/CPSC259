
/* An example to demonstrate unsafe use of pointers. Please refer to lecture notes on pointers  */

#include <stdio.h>
#include <stdlib.h>

/*
 * Returns the sum of the two integers that are passed to it by reference
 * PARAM:     int*       --  a pointer to one of the integers
 * PARAM:     int*       --  a pointer to the other integer
 * PRE:       Null
 * POST:      NULL (no side-effects)
 * RETURN:    the sum of the two integers
 */
int add_int_return(int* num1, int* num2){
  return *num1 + *num2;
}

int main( void ) {
  int num1 =2;
  int num2 =4;
  int sum;

  sum = add_int_return(&num1, &num2);
  printf("Using add_int_return: result is %d \n",sum);

  system( "PAUSE" );
  return 0;
}
