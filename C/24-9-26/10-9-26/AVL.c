
/* =========================================================
AVL TREE - Full Implementation in C
Operations included:
1. Insertion
2. Deletion
3. Search
4. Left Rotation
5. Right Rotation
6. Left-Right Rotation
7. Right-Left Rotation
8. Height calculation
9. Balance Factor calculation
10. Inorder Traversal
11. Preorder Traversal
12. Postorder Traversal
13. Level Order (BFS) Traversal
14. Find Minimum / Maximum value node
15. Count nodes / Count leaves
16. Get Height of Tree (utility)
========================================================= */
#include <stdio.h>
#include <stdlib.h>
/* ---------- Node structure ---------- */
typedef struct Node {
int key;
struct Node *left;
struct Node *right;
int height;
} Node;
/* ---------- Utility: max of two integers ---------- */
int max(int a, int b) {
return (a > b) ? a : b;
}
/* ---------- Utility: height of a node ---------- */
int height(Node *n) {
if (n == NULL)
return 0;
return n->height;
}
/* ---------- Utility: create a new node ---------- */
Node *newNode(int key) {
Node *node = (Node *)malloc(sizeof(Node));
node->key = key;
node->left = NULL;
node->right = NULL;
node->height = 1; /* new node is initially a leaf */
return node;
}
/* ---------- Right rotate subtree rooted at y ---------- */
Node *rightRotate(Node *y) {
Node *x = y->left;
Node *T2 = x->right;
/* perform rotation */
x->right = y;
y->left = T2;
/* update heights */
y->height = max(height(y->left), height(y->right)) + 1;
x->height = max(height(x->left), height(x->right)) + 1;
return x; /* new root of this subtree */
}
/* ---------- Left rotate subtree rooted at x ---------- */
Node *leftRotate(Node *x) {
Node *y = x->right;
Node *T2 = y->left;
/* perform rotation */
y->left = x;
x->right = T2;
/* update heights */
x->height = max(height(x->left), height(x->right)) + 1;
y->height = max(height(y->left), height(y->right)) + 1;
return y; /* new root of this subtree */
}
/* ---------- Get balance factor of a node ---------- */
int getBalance(Node *n) {
if (n == NULL)
return 0;
return height(n->left) - height(n->right);
}
/* ---------- Insert a key into the AVL tree ---------- */
Node *insert(Node *node, int key) {
/* 1. Perform normal BST insertion */
if (node == NULL)
return newNode(key);
if (key < node->key)
node->left = insert(node->left, key);
else if (key > node->key)
node->right = insert(node->right, key);
else
return node; /* duplicate keys not allowed */
/* 2. Update height of this ancestor node */
node->height = 1 + max(height(node->left), height(node->right));
/* 3. Get the balance factor to check if unbalanced */
int balance = getBalance(node);
/* 4. Four cases of imbalance */
/* Left Left Case */
if (balance > 1 && key < node->left->key)
return rightRotate(node);
/* Right Right Case */
if (balance < -1 && key > node->right->key)
return leftRotate(node);
/* Left Right Case */
if (balance > 1 && key > node->left->key) {
node->left = leftRotate(node->left);
return rightRotate(node);
}
/* Right Left Case */
if (balance < -1 && key < node->right->key) {
node->right = rightRotate(node->right);
return leftRotate(node);
}
/* return unchanged node pointer */
return node;
}
/* ---------- Find node with minimum key value ---------- */
Node *minValueNode(Node *node) {
Node *current = node;
while (current->left != NULL)
current = current->left;
return current;
}
/* ---------- Find node with maximum key value ---------- */
Node *maxValueNode(Node *node) {
Node *current = node;
while (current->right != NULL)
current = current->right;
return current;
}
/* ---------- Delete a key from the AVL tree ---------- */
Node *deleteNode(Node *root, int key) {
if (root == NULL)
return root;
/* 1. Perform standard BST delete */
if (key < root->key)
root->left = deleteNode(root->left, key);
else if (key > root->key)
root->right = deleteNode(root->right, key);
else {
/* node with only one child or no child */
if ((root->left == NULL) || (root->right == NULL)) {
Node *temp = root->left ? root->left : root->right;
if (temp == NULL) {
/* no child case */
temp = root;
root = NULL;
} else {
/* one child case */
*root = *temp;
}
free(temp);
} else {
/* node with two children:
get inorder successor (smallest in right subtree) */
Node *temp = minValueNode(root->right);
/* copy the inorder successor's data to this node */
root->key = temp->key;
/* delete the inorder successor */
root->right = deleteNode(root->right, temp->key);
}
}
/* if the tree had only one node, return */
if (root == NULL)
return root;
/* 2. Update height of the current node */
root->height = 1 + max(height(root->left), height(root->right));
/* 3. Get balance factor */
int balance = getBalance(root);
/* 4. Four cases of imbalance */
/* Left Left Case */
if (balance > 1 && getBalance(root->left) >= 0)
return rightRotate(root);
/* Left Right Case */
if (balance > 1 && getBalance(root->left) < 0) {
root->left = leftRotate(root->left);
return rightRotate(root);
}
/* Right Right Case */
if (balance < -1 && getBalance(root->right) <= 0)
return leftRotate(root);
/* Right Left Case */
if (balance < -1 && getBalance(root->right) > 0) {
root->right = rightRotate(root->right);
return leftRotate(root);
}
return root;
}
/* ---------- Search for a key in the AVL tree ---------- */
Node *search(Node *root, int key) {
if (root == NULL || root->key == key)
return root;
if (key < root->key)
return search(root->left, key);
return search(root->right, key);
}
/* ---------- Inorder traversal (sorted order) ---------- */
void inorder(Node *root) {
if (root != NULL) {
inorder(root->left);
printf("%d ", root->key);
inorder(root->right);
}
}
/* ---------- Preorder traversal ---------- */
void preorder(Node *root) {
if (root != NULL) {
printf("%d ", root->key);
preorder(root->left);
preorder(root->right);
}
}
/* ---------- Postorder traversal ---------- */
void postorder(Node *root) {
if (root != NULL) {
postorder(root->left);
postorder(root->right);
printf("%d ", root->key);
}
}
/* ---------- Level order (breadth-first) traversal ---------- */
void levelOrder(Node *root) {
if (root == NULL)
return;
/* simple array-based queue */
Node *queue[1000];
int front = 0, rear = 0;
queue[rear++] = root;
while (front < rear) {
Node *current = queue[front++];
printf("%d ", current->key);
if (current->left != NULL)
queue[rear++] = current->left;
if (current->right != NULL)
queue[rear++] = current->right;
}
}
/* ---------- Count total number of nodes ---------- */
int countNodes(Node *root) {
if (root == NULL)
return 0;
return 1 + countNodes(root->left) + countNodes(root->right);
}
/* ---------- Count number of leaf nodes ---------- */
int countLeaves(Node *root) {
if (root == NULL)
return 0;
if (root->left == NULL && root->right == NULL)
return 1;
return countLeaves(root->left) + countLeaves(root->right);
}
/* ---------- Free the entire tree (avoid memory leaks) ---------- */
void freeTree(Node *root) {
if (root != NULL) {
freeTree(root->left);
freeTree(root->right);
free(root);
}
}
/* ---------- Print tree structure sideways (for visualization) ---------- */
void printTree(Node *root, int space) {
const int COUNT = 6;
if (root == NULL)
return;
space += COUNT;
printTree(root->right, space);
printf("\n");
for (int i = COUNT; i < space; i++)
printf(" ");
printf("%d\n", root->key);
printTree(root->left, space);
}
/* ---------- Driver / demo program ---------- */
int main() {
Node *root = NULL;
int values[] = {10, 20, 30, 40, 50, 25, 5, 15, 35, 45};
int n = sizeof(values) / sizeof(values[0]);
printf("Inserting values: ");
for (int i = 0; i < n; i++) {
printf("%d ", values[i]);
root = insert(root, values[i]);
}
printf("\n\n");
printf("Inorder traversal (sorted): ");
inorder(root);
printf("\n");
printf("Preorder traversal: ");
preorder(root);
printf("\n");
printf("Postorder traversal: ");
postorder(root);
printf("\n");
printf("Level order traversal: ");
levelOrder(root);
printf("\n\n");
printf("Total nodes: %d\n", countNodes(root));
printf("Leaf nodes: %d\n", countLeaves(root));
printf("Tree height: %d\n", height(root));
printf("Min value: %d\n", minValueNode(root)->key);
printf("Max value: %d\n\n", maxValueNode(root)->key);
printf("Tree structure (rotated 90 degrees):");
printTree(root, 0);
printf("\n");
int searchKey = 35;
Node *found = search(root, searchKey);
printf("Search %d: %s\n", searchKey, found ? "Found" : "Not found");
printf("\nDeleting 30 (has two children)...\n");
root = deleteNode(root, 30);
printf("Inorder after deletion: ");
inorder(root);
printf("\n");
printf("\nDeleting 50 (leaf node)...\n");
root = deleteNode(root, 50);
printf("Inorder after deletion: ");
inorder(root);
printf("\n");
freeTree(root);
return 0;
}
