#include <stdio.h>
#include <stdlib.h>

int sum_elements_with_size(int a[], int size){
  int i;
  int sum = 0;
  for(i = 0; i < size; i++)
    sum += a[i];
  return sum;
}

// this should work but doesnt
int sum_elements_without_size(int a[]){
  int i    = 0;
  int sum  = 0;
  int size = sizeof(a) / sizeof(a[0]);
  for(i = 0; i < size; i++)
    sum += a[i];
  return sum;
}

int main(){
    int array[]= {1,2,3,4,5};
    int sum =0;

    int size = sizeof(array)/sizeof(array[0]);
    printf("size is %d \n", size); // 5 is returned

    sum = sum_elements_with_size(array, size);
    printf("sum is %d \n\n", sum);  // 15 is returned

    sum = sum_elements_without_size(array);
    printf("sum is %d \n\n", sum);  // 15 is returned
    return 0;
}
