#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int adj[MAX][MAX], visited[MAX], n;

int dfs(int v, int parent) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (dfs(i, v)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    int e, u, v;
    scanf("%d %d", &n, &e);
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
