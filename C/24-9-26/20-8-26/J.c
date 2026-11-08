#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
}Node;


Node* createNode(int value) {
     Node *newNode = malloc(sizeof( Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

Head* createHead(int value) {
     Head *newHead = malloc(sizeof( Head));

    newHead->data = value;
    newHead->next = NULL;
    newHead->down = NULL;

    return newHead;
}
void display()
{
    struct Node *temp = head;

    if (head == NULL)
    {
        printf("Linked List is Empty.\n");
        return;
    }

    printf("Linked List: ");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

