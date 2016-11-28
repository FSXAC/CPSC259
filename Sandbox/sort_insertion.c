void insertion_sort(int *data, int size) {
  int i;
  int temp;
  int pos;

  // moving forward
  for (i = 1; i < size; i++) {
    temp = data[i];
    pos  = i - 1;

    // shifting everthing behind i forward when i is smaller
    while (pos >= 0 && data[pos] > temp) {
      data[pos + 1] = data[pos];
      pos--;
    }

    // "insert" current sorting value 
    data[pos + 1] = temp;
  }
}
