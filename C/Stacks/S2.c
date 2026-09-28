#include<stdio.h>
#define MAX 15

int stack[MAX];
int top = -1;

void getInput(int value )
{
    int i,n;
    if(top == MAX-1)
    {
        printf("Stack Overflow\n");
        return;

    }

    printf("Enter the number of elements to push: ");
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &value);
        top++;
        stack[top] = value;
    }


}
void pushOdd(int value)
{
    if(value%2!=0)
    {
        

    }
}