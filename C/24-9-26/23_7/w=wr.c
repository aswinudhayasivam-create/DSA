#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
typedef enum { FALSE, TRUE } Bool;
typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;
Stack createStack()
{
    Stack s;
    s.top = -1;
    return s;
}
int isEmpty(Stack s)
{
    return s.top == -1;
}
Bool push(Stack *s, char ch)
{
    if (s->top == MAX_SIZE - 1)
        return FALSE;
    s->arr[++s->top] = ch;
    return TRUE;
}
Bool pop(Stack *s, char *ch)
{
    if (isEmpty(*s))
        return FALSE;
    *ch = s->arr[s->top--];
    return TRUE;
}
int main()
{
    Stack s = createStack();
    char str[MAX_SIZE];
    int i = 0;
    printf("Enter string w = w form : ");
    scanf("%s", str);
    while (str[i] != '=' && str[i] != '\0')
    {
        push(&s, str[i]);
        i++;
    }
    i++;
    while(str[i]!='\0')
    {
        char ch;
        if (pop(&s,&ch)==FALSE||ch!=str[i])
        {
            printf("Not in reverse form\n");
            return 0;
        }
        i++;
    }
    if (isEmpty(s))
        printf("In reverse form\n");
    else
        printf("Not in reverse form\n");

    return 0;
}
