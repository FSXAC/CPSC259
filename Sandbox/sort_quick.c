// find and return the index of pivot element
// 1. pick a pivot
// 2. all elements < pivot reordered to left
//    all elements >= pivot reordered to right
// 3. recursively sort each side
//
// Time Best   : O(nlogn)
// Time Average: O(nlogn)
// Time Worst  : O(n^2)

// function for swapping two integers
void swap(int *a, int *b) {
  int temp = *a;
  *a       = *b;
  *b       = temp;
}

// returns the ideal pivot element
// make everything left of pivot is smaller (right is bigger)
int partition(int *data, int low, int high) {
  int count;
  int i = low;

  // select first element in the partition as pivot
  int pivotElement = data[low];

  // shift (continuously swapping) pivot to right location
  for (count = low + 1; count <= high; count++) // XXX

    // skips if numbers are larger than pivot
    if (data[count] <= pivotElement)
      swap(&data[count], &data[i++]);

  // swap pivot so everything left side is smaller
  swap(&data[i], &data[low]);
  return i;
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
