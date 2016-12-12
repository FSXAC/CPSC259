// heap
// mappig into array:
// left child index    = 2 * current index + 1
// right child index   = 2 * current index + 2
// parent index        = floor((node - 1) / 2)
// next availabe index = length (of array)
// root                = 0

// swap two numbers
void swap(int *a, int *b) {
  int temp = *a;
  *a       = *b;
  *b       = temp;
}

// get parent index
int getParent(int child) {
  return (child - 1) / 2;
}

// check if the node is a leaf
int isLeaf(int top, int bottom) {
  return (
    (2 * top + 1 < bottom) ||
    (2 * top + 2 < bottom)
  );
}

// get the index of maximum child
int getMaxChild(int top) {
  int left  = 2 * top + 1;
  int right = left + 1;

  // need FIXME
  // if only has single child
  // if (right > ) return left;
  //
  // // choose the maximum
  return (left > right) ? left : right;
}

// adding an item to a heap (using reheap up)
// top - root
// bottom - index of added element
void reheapUp(int *data, int top, int bottom) {
  // stop if bottom is in front (above) top
  if (bottom < top) return;

  int parent = getParent(bottom);
  if (data[parent] < data[bottom]) {
    swap(&data[parent], &data[bottom]);

    // recursivly reheap with parent index since swap
    reheapUp(data, top, parent);
  }
}

// removing an item:
// first swap root with last element
// then reheap` (using reheap down)
// top - root, bottom - final element in the heap
void reheapDown(int *data, int top, int bottom) {
  // check if top is a leaf
  if (isLeaf(top, bottom)) return;

  int maxChild = getMaxChild(top);

  if (data[top] < data[maxChild]) {
    swap(&data[top], &data[maxChild]);
    reheapDown(data, maxChild, bottom);
  }
}

// heapify - turn an array into a heapify
void heapify(int *data, int top, int bottom) {
  int index =
}
