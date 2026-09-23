#include<stdio.h>
#include<stdlib.h>

typedef struct NODE {
    int data;
    struct NODE *next;
} NODE;

NODE* makeNode(int data, NODE* next)
{
    NODE* t = (NODE*)malloc(sizeof(NODE));
    t->data = data;
    t->next = next;
    return t;
}

NODE* deletePos(NODE* l, int pos) {
    if (!l) return l;
    if (pos == 1) return l->next;

    int cp = 1;
    NODE* t = l;
    while (cp < pos - 1 && t->next)
    {
        t = t->next;
        cp++;
    }
    if (t->next) t->next = (t->next)->next;
    return l;
}

NODE* deletePosRec(NODE* l, int pos, int cp)
{
    if (!l) return l;
    if (pos == cp) return l->next;
    l->next = deletePosRec(l->next, pos, cp + 1);
    return l;
}

NODE* inSort(NODE* l, int data)
{
    if (!l) return makeNode(data, NULL);
    if (l->data > data)
    {
        return makeNode(data, l);
    }
    l->next = inSort(l->next, data);
    return l;
}

NODE* delSort(NODE* l, int data)
{
    if (!l) return l;
    if (l->data > data) return l;
    if (l->data == data) return l->next;

    l->next = delSort(l->next, data);
    return l;
}

/* ---- small demo so you can see it actually working ---- */
void display(NODE* l) {
    while (l) {
        printf("%d", l->data);
        if (l->next) printf(" -> ");
        l = l->next;
    }
    printf("\n");
}

int main(void) {
    NODE* l = makeNode(10, makeNode(20, makeNode(30, makeNode(40, NULL))));
    printf("Original list: "); display(l);

    l = deletePos(l, 2);
    printf("After deletePos(l, 2): "); display(l);

    l = deletePosRec(l, 1, 1);
    printf("After deletePosRec(l, 1, 1): "); display(l);

    l = inSort(l, 25);
    printf("After inSort(l, 25): "); display(l);

    l = delSort(l, 30);
    printf("After delSort(l, 30): "); display(l);

    return 0;
}