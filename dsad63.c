#include <stdio.h>
#include <stdlib.h>

int visited[100];

void dfs(int v, int n, int adj[100][100]) {
    visited[v] = 1;
    printf("%d ", v);
    for(int i = 0; i < n; i++) {
        if(adj[v][i] && !visited[i]) {
            dfs(i, n, adj);
        }
    }
}

int main() {
    int n, s;
    scanf("%d", &n);
    int adj[100][100] = {0};
    for(int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);
        for(int j = 0; j < k; j++) {
            int x;
            scanf("%d", &x);
            adj[i][x] = 1;
        }
    }
    scanf("%d", &s);
    dfs(s, n, adj);
    return 0;
}
