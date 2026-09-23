#include <stdio.h>
#include <malloc.h>


typedef struct btree { int data; struct btree *left, *right; } BTREE;

BTREE * makeNode(int data)
{ BTREE *t = (BTREE *) malloc(sizeof(BTREE));
t->data = data; t->left = NULL; t->right = NULL;
return t;
}
BTREE *createByDepth()
{   int data;
    scanf("%d", &data);
    if(data) {  BTREE *newNode = makeNode(data);
                printf("Left of %d <int> ... ", newNode->data);
                newNode->left = createByDepth();
                printf("Right of %d <int> ... ", newNode->data);
                newNode->right = createByDepth();
                return newNode;
            }
    return NULL;
}

BTREE * createByLevel()

{
BTREE *root, *current, *Q[20];
int r = 0, f = 0, data;
printf("Root node value <int> ... "); scanf("%d", &data);
if (!data) return NULL;
root = makeNode(data); current = root; Q[++r] = root;
while (f != r)
{   current = Q[++f];
    printf("Left of %d ", current->data);
    scanf("%d",&data);
    if (data) {
    current->left = makeNode(data);
    Q[++r] = current->left;
   }
        printf("Right of %d ", current->data);
scanf("%d",&data);
    if (data) {
current->right = makeNode(data);
Q[++r] = current->right;
     }
}
return root;
}

void display(BTREE *t)

{
BTREE *current, *Q[50]; int r = 0, f = 0;
if (t) Q[++r] = t;

while (f != r)
{   current = Q[++f];
printf("[%5d] ",current->data);
if (current->left) Q[++r] = current->left;
if (current->right)Q[++r] = current->right;
}
}


int main()
{
    BTREE *t = NULL;
    printf("Root value "); t = createByDepth();
    printf("Traversal Output"); display(t);
    return 0;
}