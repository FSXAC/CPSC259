// find and return the index of pivot element
// 1. pick a pivot
// 2. all elements < pivot reordered to left
//    all elements >= pivot reordered to right
// 3. recursively sort each side
//
// Time Best   : O(nlogn)
// Time Average: O(nlogn)
// Time Worst  : O(n^2)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_SIZE 1000

void printArray(int *array, int n);

// function for swapping two integers
void swap(int *a, int *b) {
  int temp = *a;
  *a       = *b;
  *b       = temp;
}

// returns the ideal pivot element
// make everything left of pivot is smaller (right is bigger)
int partition(int *data, int low, int high) {
  // choose first element as pivot
  int pivotValue = data[low];
  // printf("\nPivot: %d, low: [%d], high: [%d]\n", pivotValue, low, high);

  int storeIndex = low + 1;

  for (int i = low + 1; i <= high; i++) {
    // if elements greater than pivot exists, put them behind the pivot
    if (data[i] < pivotValue) {
      // printf("Swapping %d and %d:\t\t", data[i], data[storeIndex]);
      swap(&data[i], &data[storeIndex++]);
      // printArray(data, 10);
    }
  }

  // swap end of this partition with pivot, pivot is now at storeIndex - 1
  // printf("Pivoting %d and %d:\t\t", data[low], data[storeIndex - 1]);
  swap(&data[low], &data[storeIndex - 1]);
  // printArray(data, 10);

  return storeIndex - 1;
}

// recursive sorting helper function for quicksort
void qSort(int *data, int low, int high) {
  // base condition, quit if center is reached
  if (low >= high) return;

  // get pivot element
  int pivot = partition(data, low, high);

  // recursively sort everything left and right of pivot
  qSort(data, low,       pivot);
  qSort(data, pivot + 1, high );
}

// main function for quick sorting
void quickSort(int *data, int size) {
  qSort(data, 0, size - 1);
}

// print array
void printArray(int *array, int n) {
  printf("[");
  for (int i = 0; i < n; i++) printf(" %d,", array[i]);
  printf("\b ]\n");
}

int main(void) {
  int *test_array = (int *)malloc(sizeof(int) * TEST_SIZE);

  // timing
  clock_t start, end;

  // generate random numbers
  for (int i = 0; i < TEST_SIZE; i++) {
    test_array[i] = rand() % 100;
  }

  start = clock();

  printf("Unsorted:\t\t\t");
  printArray(test_array, TEST_SIZE);

  quickSort(test_array, TEST_SIZE);
  printf("Sorted:\t\t\t\t");
  printArray(test_array, TEST_SIZE);

  end = clock();

  printf("Performance: %fs\n", (double) (end - start) / CLOCKS_PER_SEC);

  system("pause");
  return 0;
}
