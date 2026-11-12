#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct STACK
{
  char *val;
  int top;
  int n;
} STACK;

STACK createStack(int length)
{
    STACK s;
    s.top = 0;
    s.val = (char *)malloc(length * sizeof(char));
    s.n = length;
    return s;
}

bool isFull(STACK *s)
{
    if(s->top == s->n) return 1;
    return 0;
}

bool isEmpty(STACK *s)
{
    if(s->top == 0) return 1;
    return 0;
}

bool push(STACK *s, char x)
{
    if(isFull(s)) return 0;
    s->val[s->top] = x;
    s->top++;
    return 1;
}

bool pop(STACK *s, char *x)
{
    if(isEmpty(s)) return 0;
    *x = s->val[s->top - 1];
    s->top--;
    return 1;
}

char peek(STACK s)
{
    return s.val[s.top - 1];
}

void postfix(STACK *stk, char *s)
{
    char x;
    for(int i = 0; s[i] != '\0'; i++)
    {
        switch(s[i]){
               {
                   case '(':
                    {
                        break;
                    }
                   case ')':
                       {
                          pop(stk, &x);
                          printf("%c", x);
                          break;
                       }
                 }
                   case '+':
                   case '-':
                   case '*':
                   case '^':
                   case '/':
                   case '?':
                   case ':':
                   case '%':
                    {
                        push(stk, s[i]);
                        break;
                    }
                    default :{
                        printf("%c", s[i]);
                        break;
                    }
        }
    }
}

int main()
{
    char str[100];
    printf("Enter a fully paranthesised exprreession : \n");
    scanf("%s", str);

    int len = strlen(str);
    STACK stk = createStack(len);
    postfix(&stk, str);

    free(stk.val);
    return 0;
}
