#include <stdio.h>
int findMax(int a[], int n)
{
 int max = a[0];
 int i;
 for (i = 1; i < n; i++)
 {
 if (a[i] > max)
 max = a[i];
 }
 return max;
}
void countingSort(int a[], int n)
{
 int count[1000] = {0};
 int max, i, j, k = 0;
 max = findMax(a, n);
 for (i = 0; i < n; i++)
 count[a[i]]++;
 for (i = 0; i <= max; i++)
 {
 for (j = 0; j < count[i]; j++)
 {
 a[k] = i;
 k++;
 }
 }
}
int main()
{
 int a[100], n, i;
 printf("Enter number of elements: ");
 scanf("%d", &n);
 printf("Enter non-negative integers:\n");
 for (i = 0; i < n; i++)
 scanf("%d", &a[i]);
 countingSort(a, n);
 printf("Sorted array:\n");
 for (i = 0; i < n; i++)
 printf("%d ", a[i]);
 return 0;
}
