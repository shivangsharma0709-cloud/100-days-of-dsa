/*

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left

*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    int in=0;
    printf("Enter the value in n");
    scanf("%d",&n);

    int *ptr;
    ptr=(int *)malloc(n*sizeof(int));

    printf("Enter the elements in array \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }

    printf("Elements in array are \n");

    for(int i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }

    printf("\nEnter the index from where the number is to be removed \n");
    scanf("%d",&in);

    for (int i = in; i < n - 1; i++)
    {
        ptr[i] = ptr[i + 1];
    }

    printf("Array after deletion:\n");
    for (int i = 0; i < n - 1; i++)
    {
        printf("%d ", ptr[i]);
    }

    free(ptr);
}
