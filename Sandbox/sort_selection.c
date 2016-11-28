// swap two values
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// finds the minimum value's index
void getMinPos(int *data, int from, int to) {
  int min = from;
  int i;
  for (i = from + 1; i < to; i++)
    if (data[i] < data[min]) min = i;
  return min;
}


void selection_sort(int *data, int size) {
  int i, min;
  for (i = 0; i < size; i++) {
    min = getMinPos(data, i, size);
    if (min != i) swap(&data[i], &data[min]);
  }
}
