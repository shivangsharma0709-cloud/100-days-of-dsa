#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main() {
    int N, i;
    int queue[MAX], stack[MAX];
    int front = 0, rear, top = -1;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &queue[i]);
    }
    rear = N - 1;

    for (i = front; i <= rear; i++) {
        stack[++top] = queue[i];
    }

    for (i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}