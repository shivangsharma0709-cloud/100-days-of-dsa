#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int recStack[MAX];
int V;

int dfs(int v) {
    visited[v] = 1;
    recStack[v] = 1;

    for (int i = 0; i < V; i++) {
        if (graph[v][i]) {
            if (!visited[i] && dfs(i))
                return 1;
            else if (recStack[i])
                return 1;
        }
    }

    recStack[v] = 0;
    return 0;
}

int main() {
    scanf("%d", &V);
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < V; i++)
        if (!visited[i] && dfs(i)) {
            printf("YES\n");
            return 0;
        }

    printf("NO\n");
    return 0;
}
