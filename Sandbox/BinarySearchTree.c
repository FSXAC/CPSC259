// file: binary_search_tree.c

# include <stdio.h>
# include <stdlib.h>

struct BNode* createTree(int item);
struct BNode * find( struct BNode * root, int item );
struct BNode * makeNode(int item, struct BNode * leftChild,  struct BNode * rightChild);
void addNode(struct BNode * root, int item);

struct BNode* deleteNode(struct BNode* root, int item);
struct BNode* findParent(struct BNode * root, int item);

void printPreorder(struct BNode* node);
void printInorder(struct BNode* node);
void printPostorder(struct BNode* node);


struct BNode {
  int             item;
  struct BNode *  left;
  struct BNode *  right;
};


/* a new node is created and its address is returned */
struct BNode * makeNode(int item, struct BNode * leftChild,
                        struct BNode * rightChild) {
  struct BNode *  temp;
  temp = (struct BNode *)malloc(sizeof(struct BNode));

  temp->item 	= item;
  temp->left 	= leftChild;
  temp->right	= rightChild;

  return temp;
}

struct BNode* createTree(int item) {
  return makeNode(item, NULL, NULL);
}



/*  Assuming root points to the root of a binary tree, if item is
 *  in the tree, return the address of its node; otherwise, return NULL
 */
struct BNode * find( struct BNode * root, int item ) {
  // if empty or first thing is correct, return it
  if (root == NULL || root->item == item) return root;

  // recursive find
  if (item < root->item) return find(root->left, item);   // go L if we're too big
  else return find(root->right, item);                    // go R if we're too small
}

/*  Assuming root points to the root of a binary tree, and items are unique */
void addNode(struct BNode * root, int item) {
  if (item < root->item) {
    /* root->left is the same as root->left!=NULL */
    if (root->left) addNode(root->left, item);
    else root->left = makeNode(item, NULL, NULL);
  }

  if (item > root->item) {
    /* root->right is the same as root->right!=NULL */
    if (root->right) addNode(root->right, item);
    else root->right = makeNode(item, NULL, NULL);
  }
}

struct BNode* deleteNode(struct BNode* root, int item) {
  struct BNode* parent=NULL;
  struct BNode* target = find(root, item);

  if (!target) return root; /* item not in tree */

  /* current now points to the node that needs to be deleted. */
  parent = findParent(root, item);

  if (target->left == NULL && target->right ==NULL){
    /* --------------------- leaf----------------------- */
    if (parent != NULL){
      if (parent->left == target) parent ->left = NULL;
      else parent ->right = NULL;
    }
    // parent == NULL
    else root = NULL;
    free(target);
    return root;
  }


  if (target->left != NULL && target->right == NULL){
    /* --------------------- Only left child----------------- */

    if (parent != NULL) {
      if ( parent->left == target ) parent->left = target->left;
      else parent->right = target->left;
    }
    else root = target->left;

    free(target);
    return root;
  }


  if (target->left == NULL && target->right !=NULL){
    /* --------------------- Only right child----------------- */

    if (parent != NULL) {
      if ( parent->left == target ) parent->left = target->right;
      else parent->right = target->right;
    }
    else root = target->right;

    free(target);
    return root;
  }


  /* --------------------- Two children ----------------- */
  if (target->left != NULL && target->right != NULL) {

    /* find the replacing node, rightmost child of left subtree */
    struct BNode* temp = target->left;
    struct BNode* previous = target;
    while (temp->right != NULL) {
        previous = temp;
        temp = temp->right;
    }
    target->item = temp->item;
    if (target == previous)
        previous->left = temp->left; /* replaced by left child */
    else
    /* could either be Null or temp has a left child */
        previous->right = temp->left;

    free(temp);
    temp = NULL;
  }

  return root; // return root when you're done.
}



/**
 * Finds the parent of node in the tree rooted at rootNode
 */
struct BNode* findParent(struct BNode * root, int item) {
  // if item is already parent or tree is empty
  if (root == NULL || root->item == item) return NULL;

  //
  else if (root->left && (root->left->item == item)) return root;

  else if (root->right && (root->right->item == item)) return root;

  else if (item < root->item ) return findParent(root->left, item);
  else                         return findParent(root->right, item);
}


/*---------------Traversing----------------------*/

/* Given a binary tree, print its nodes according to the
 "bottom-up" postorder traversal. */
void printPostorder(struct BNode* node) {
    if (node == NULL) return;

    // first recur on left subtreeode->left);

    // then recur on right subtree
    printPostorder(node->right);

    // now deal with the node
    printf("%d ", node->item);
}

/* Given a binary tree, print its nodes in inorder*/
void printInorder(struct BNode* node) {
    if (node == NULL) return;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    printf("%d ", node->item);

    /* now recur on right child */
    printInorder(node->right);
}

/* Given a binary tree, print its nodes in preorder*/
void printPreorder(struct BNode* node) {
    if (node == NULL) return;

    /* first print data of node */
    printf("%d ", node->item);

    /* then recur on left sutree */
    printPreorder(node->left);

    /* now recur on right subtree */
    printPreorder(node->right);
}

/*---------------Driver -----------------------*/

/* Note that original implementation left deleting a node with two childeren
 as an exercise, but it is completed in this version. */

int main() {

    struct BNode* root = createTree(10);
    addNode(root, 20);
    addNode(root, 5);
    addNode(root, 15);
    addNode(root, 25);
    addNode(root, 7);
    addNode(root, 35);
    while (root) {
        printInorder(root);
        printf("root=%d\n", root->item);
        root = deleteNode(root, root->item);
    }

    //    system("pause");   // LC
    return 0;
}
