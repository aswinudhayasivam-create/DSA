#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void headNode(Node **head, int val) {
    Node* newNode = createNode(val); // Fixed: changed 'sreateNode' to 'createNode'

    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }

    *head = newNode;
    printf("Inserted %d at the head of the list.\n", val);
}

void tailNode(Node **head, int val) {
    Node* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        printf("Inserted %d at end.\n", val); // Fixed: added 'val' argument
        return;
    }
    
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
    printf("Inserted %d at end.\n", val); // Fixed: added 'val' argument
}

void deleteNode(Node **head, int val) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;

    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found.\n", val); // Fixed: added 'val' argument
        return;
    }

    if (*head == temp) {
        *head = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    free(temp); // Added: free memory to prevent leaks
    printf("Deleted %d from the list.\n", val);
}

void revList(Node **head) {
    if (*head == NULL)
        return;
        
    Node *temp = NULL; // Fixed: replaced ':' with ';'
    Node *current = *head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
    printf("List reversed successfully.\n");
}

void displayList(Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("List Contents: ");
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    } // Fixed: added missing closing brace for while loop
    printf("\n");
}

int main() {
    Node *head = NULL;
    
    headNode(&head, 10);
    headNode(&head, 20);
    tailNode(&head, 30);
    tailNode(&head, 40);

    displayList(head);

    deleteNode(&head, 20);
    displayList(head);

    revList(&head);
    displayList(head);

    return 0;
}