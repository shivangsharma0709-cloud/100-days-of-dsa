/*

Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)

*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    int num;
    printf("Enter a number");
    scanf("%d",&n);

    int *ptr;
    ptr=(int *)malloc(n*sizeof(int));

    printf("Enter the array's element \n ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ptr[i]);
    }

    printf("The array elements are \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",ptr[i]);
    }

    printf("\nEnter a number to be searced");
    scanf("%d",&num);

    int count=0;

    for(int i=0;i<n;i++)
    {
        if(ptr[i]==num)
        {
            count=n-i;
            printf("Found at index %d",i);
        }
    }
    printf(" \n Comparisons=%d",count);

    free(ptr);
}
