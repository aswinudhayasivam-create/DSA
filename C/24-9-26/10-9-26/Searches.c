#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 4000
#define S 50000

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

ListNode *insertList(ListNode *head, int value)
{
    ListNode *newNode = malloc(sizeof(ListNode));

    newNode->data = value;
    newNode->next = head;

    return newNode;
}

ListNode *createList(int arr[])
{
    ListNode *head = NULL;

    for (int i = 0; i < N; i++)
        head = insertList(head, arr[i]);

    return head;
}

int searchList(ListNode *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
            return 1;

        head = head->next;
    }

    return 0;
}

int main()
{
    int arr[N];
    int keys[S];
    ListNode *list;
    int failure = 0;

    srand(time(NULL));


    return 0;
}

