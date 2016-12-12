// Q1
// B C

// Q2
// A E

// Q3

// Q7
struct node {
  int value;
  struct node *left;
  struct node *right;
};

int count(struct node *root) {
  if (!root) return 0;
  return 1 + count(root->left) + count(root->right);
}

// Q8
struct Bnode {
  int value;
  struct node *left;
  struct node *right;
};

int height(struct Bnode *root) {
  // check if it's a leaf or empty
  if (!root || (!(root->left) && !(root->right))) return 0;

  // check if left side or right side is deeper
  int left  = height(root->left);
  int right = height(root->right);
  return 1 + ((left > right) ? left : right);
}
