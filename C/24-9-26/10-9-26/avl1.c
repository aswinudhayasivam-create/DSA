typedef struct Node {
int key;
struct Node *left;
struct Node *right;
int height;
} Node;

Node *newNode(int key) {
Node *node = (Node *)malloc(sizeof(Node));
node->key = key;
node->left = NULL;
node->right = NULL;
node->height = 1;
return node;
}
