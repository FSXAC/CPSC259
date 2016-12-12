
/* An example to demonstrate using pointers to calculate area of a triangle */

#include <stdio.h>
#include <stdlib.h>

void calculate_triangle(float *base, float *height, float *area){
  *area = *base * *height / 2;
}

int main( void ) {
  float base = 5;
  float height = 7;
  float area;

  calculate_triangle(&base, &height, &area);
  printf("Area of triangle: %f \n", area);
  return 0;
}
