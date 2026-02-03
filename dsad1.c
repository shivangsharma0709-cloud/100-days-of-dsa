/*

Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right

*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    int num;
    int in;
    printf("Enter the number of the element \n");
    scanf("%d",&n);

    int *ptr;

    ptr=(int *)malloc(n*sizeof(int));

    printf("Enter the elements in the ptr \n");

    for(int i=0;i<n;i++)
    {
        printf("Enter a number at %d index \n",i);
        scanf("%d",&ptr[i]);
    }

    printf("\n");

    for(int i=0;i<n;i++)
    {
        printf("the element at the %d index is %d \n",i,ptr[i]);
    }

    printf("Enter a number to be inserted \n");
    scanf("%d",&num);
    printf("Enter the index at which number is to be inserted \n");
    scanf("%d",&in);

    ptr=(int *)realloc(ptr,(n+1)*sizeof(int));

    for(int i=n;i>in;i--)
    {
        ptr[i]=ptr[i-1];
    }

    ptr[in]=num;

    printf("New array after the reallocation \n");

    for(int i=0;i<=n;i++)
    {
        printf("the element at the %d index is %d \n",i,ptr[i]);
    }

    free(ptr);

}

