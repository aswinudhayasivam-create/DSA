#include <stdio.h>
#include <stdlib.h>
 struct Node {
    char data;
    int state;
    struct Node *left;
    struct Node *right;
};
 struct Node* createNode(char data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->state = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 struct Node* search(struct Node *root, char data) {
    if (root == NULL || root->data == data)
        return root;
     if (data < root->data)
        return search(root->left, data);
    return search(root->right, data);
}
struct Node* insert(struct Node *root, char data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    return root;
}
int validate(char str[]) {
    struct Node *root = NULL;
    struct Node *temp;
    int i = 0;
    while (str[i] != '\0') {
        char operation = str[i];
        char variable = str[i + 1];
        if (variable == '\0')
            return 0;
        temp = search(root, variable);
        if (operation == 'D') {
            if (temp != NULL)
                return 0;
            root = insert(root, variable);
        }
        else if (operation == 'U') {
            if (temp == NULL || temp->state == 0)
                return 0;
        }
        else if (operation == 'K') {
            if (temp == NULL || temp->state == 0)
                return 0;
            temp->state = 0;
        }
                else {
            return 0;
        }
        i += 2;
    }
    return 1;
}
int main() {
    char str[100];
    printf("Enter sequence: ");
    scanf("%s", str);
    if (validate(str))
        printf("Valid sequence\n");
    else
        printf("Invalid sequence\n");
    return 0;
}

