#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} NODE;

int main()
{
    NODE *head = NULL;
    head = (NODE*)malloc(sizeof(struct node));
    
    head->data = 100;
    head->next = NULL;
    printf("%d", head->data);
    return 0;
}
