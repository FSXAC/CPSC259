// swaps two values at a time
// takes ages to sort (average and worst)

void swap(int *a, int *b) {
  int temp = *a;
  *a       = *b;
  *b       = temp;
}

void bubbleSort(int *data, int size) {
  int i, j;
  int flag = 1;

  for (i = 0; (i <= size) && flag; i++) {
    flag = 0;

    for (j = 0; j < n - 1; j++) {
      if (data[j] > data[j + 1]) {
        // if swap if left is > right
        swap(&data[j], &data[j + 1]);

        // reset flag to indicate swap occurance
        flag = 1;
      }
    }
  }
}
