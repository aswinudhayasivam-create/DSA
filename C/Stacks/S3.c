#include <stdio.h>
#include<string.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int top;

} Stack;

void initStack(Stack *s)
{
    s->top =-1;

}
void push(Stack *s,char ch)
{
    if(s->top == MAX -1 )
    return;
    s->data[++s->top] = ch;

}

char pop(Stack *s)
{
    if(s->top == -1)
    return '\0';
    return s->data[(s->top)--];

}
int main()
{
    Stack s;
    char str[MAX];
    int i;

    initStack(&s);
 
    printf("Enter a String: ");

        fgets(str,MAX,stdin);
        str[strcspn(str,"\n")] = '\0';

    for(i=0;str[i]!='\0';i++)
    {
        push(&s,str[i]);
    }

    printf("Reversed String: ");
    while(s.top != -1)
    {
        printf("%c",pop(&s));
    }
    printf("\n");
    return 0;
}