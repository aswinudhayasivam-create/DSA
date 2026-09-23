#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

NODE *makeNode(int data)
{
    NODE *temp = (NODE*)malloc(sizeof(NODE));
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    temp->data = data;
    temp->next = NULL;
    return temp;
}

NODE *insertHead(NODE *L, int data)
{
    NODE *temp = makeNode(data);
    temp->next = L;
    return temp;
}

void display(NODE *L)
{
    while (L != NULL)
    {
        printf("%d -> ", L->data);
        L = L->next;
    }
    printf("NULL\n");
}

void freeList(NODE *head)
{
    NODE *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    NODE *head = NULL;

    // Building a linked list by inserting at the head
    head = insertHead(head, 400);
    head = insertHead(head, 300);
    head = insertHead(head, 200);
    head = insertHead(head, 100);

    // Display the entire linked list
    display(head);

    // Free allocated memory
    freeList(head);

    return 0;
}