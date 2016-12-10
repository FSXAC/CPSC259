// merge sort - divide and conquer method
// 1. split array into two halves
// 2. recursively sort each half
// 3. merge the two sorted to a larger sorted array

// merge two adjascent ranges in array
void merge(int *data, int low, int mid, int high, int *temp) {
  // a - pointer for lower half
  // b - pointer for upper half
  // k - incrementer for the entire array
  int a = low;
  int b = mid + 1;
  int k;

  // iterate through the whole array
  for (k = low; k <= high; k++) {

    // if:
    // A still has items (<= mid) and
    // current element in A is smaller than B or
    // B is exhausted
    // then: choose A to add to list
    if (a <= mid && (b > high || data[a] < data[b]))
      temp[k] = data[a++];
    else
      temp[k] = data[b++];
  }

  // copy the items in temporary to the actual array
  for (k = 0; k < high; k++) data[k] = temp[k];
}

// recursive sorting function
void mSort(int *data, int low, int high, int *temp) {
  // base cases, stop splitting
  if (low >= high) return;

  // set a middle point, then recursively call the function to sort divided part
  int mid = (high + low) / 2;
  mSort(data, low    , mid , temp);
  mSort(data, mid + 1, high, temp);

  // merge the sorted together
  merge(data, low, mid, high, temp);
}

// main merge sort function
void mergeSort(int *data, int size) {
  // create temporary array for sorting
  int *temp =(int *)malloc(size * sizeof(int));

  // start recursive sorting
  mSort(data, 0, size, temp);

  // free memory for temp
  free(temp);
}
