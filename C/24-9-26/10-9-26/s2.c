
#include <stdio.h>
#include <stdlib.h>

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
    int success = 0;
    int failure = 0;

    srand(1);

    for (int i = 0; i < N; i++)
    {
        arr[i] = 1000 + rand() % 9000;
    }

    list = createList(arr);

    for (int i = 0; i < 40950; i++)
    {
        keys[i] = arr[i % N];
    }

    for (int i = 40950; i < S; i++)
    {
        int key;

        do
        {
            key = 1000 + rand() % 9000;
        }
        while (searchList(list, key));

        keys[i] = key;
    }

    for (int i = 0; i < S; i++)
    {
        if (searchList(list, keys[i]))
            success++;
        else
            failure++;
    }

    printf("Linked List    : %d success, %d fail\n",
           success, failure);

    return 0;
}
