#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct Head {
    int data;
    struct Node *next;
    struct Head *down;
}Head;

 Node* createNode(int value) {
    Node *newNode = malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}
Head* createHead(int value) {
    Head *newHead = malloc(sizeof(Head));

    newHead->data = value;
    newHead->next = NULL;
    newHead->down = NULL;

    return newHead;
}

void display(Head *head) {
    Head *h = head;

    while (h != NULL) {
        printf("%d -> ", h->data);

        Node *temp = h->next;

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
        h = h->down;
    }
}

int main() {
    int n, count, value;

    Head *head = NULL;
    Head *lastHead = NULL;

    srand(time(NULL));

    printf("Enter number of linked lists: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {

        count = rand() % 5 + 1;

        value = rand() % 100 + 1;

       Head *newHead = createHead(value);
       Node *last = NULL;

        for (int j = 1; j < count; j++) {

            value = rand() % 100 + 1;

             Node *newNode = createNode(value);

            if (newHead->next == NULL) {
                newHead->next = newNode;
                last = newNode;
            } else {
                last->next = newNode;
                last = newNode;
            }
        }

        if (head == NULL) {
            head = newHead;
            lastHead = newHead;
        } else {
            lastHead->down = newHead;
            lastHead = newHead;
        }
    }

    printf("\nJagged Array:\n");
    display(head);

    return 0;
}
