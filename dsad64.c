#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int v) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void bfs(int n, int adj[n][n], int s) {
    int i;
    for (i = 0; i < n; i++) visited[i] = 0;
    enqueue(s);
    visited[s] = 1;
    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        for (i = 0; i < n; i++) {
            if (adj[u][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, s, i, j;
    scanf("%d", &n);
    int adj[n][n];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    scanf("%d", &s);
    bfs(n, adj, s);
    return 0;
}
