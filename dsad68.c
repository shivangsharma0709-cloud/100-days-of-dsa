#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
    int n, e, i, j;
    int adj[MAX][MAX], indegree[MAX], queue[MAX], front = 0, rear = 0;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);

    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        for (j = 0; j < n; j++) adj[i][j] = 0;
    }

    for (i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }

    for (i = 0; i < n; i++)
        if (indegree[i] == 0) queue[rear++] = i;

    int count = 0;
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        count++;
        for (v = 0; v < n; v++) {
            if (adj[u][v]) {
                indegree[v]--;
                if (indegree[v] == 0) queue[rear++] = v;
            }
        }
    }

    if (count != n) printf("\nCycle detected\n");
    return 0;
}
