#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int vertex;
    int dist;
} Node;

typedef struct {
    Node heap[MAX];
    int size;
} PriorityQueue;

void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void push(PriorityQueue *pq, int vertex, int dist) {
    pq->heap[pq->size].vertex = vertex;
    pq->heap[pq->size].dist = dist;
    int i = pq->size++;
    while (i && pq->heap[(i - 1) / 2].dist > pq->heap[i].dist) {
        swap(&pq->heap[i], &pq->heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

Node pop(PriorityQueue *pq) {
    Node root = pq->heap[0];
    pq->heap[0] = pq->heap[--pq->size];
    int i = 0;
    while (1) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (left < pq->size && pq->heap[left].dist < pq->heap[smallest].dist) smallest = left;
        if (right < pq->size && pq->heap[right].dist < pq->heap[smallest].dist) smallest = right;
        if (smallest == i) break;
        swap(&pq->heap[i], &pq->heap[smallest]);
        i = smallest;
    }
    return root;
}

int empty(PriorityQueue *pq) {
    return pq->size == 0;
}

int main() {
    int n, e, i, j;
    int adj[MAX][MAX], dist[MAX], visited[MAX];
    PriorityQueue pq = {.size = 0};

    scanf("%d %d", &n, &e);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) adj[i][j] = 0;
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    for (i = 0; i < e; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }

    int src;
    scanf("%d", &src);
    dist[src] = 0;
    push(&pq, src, 0);

    while (!empty(&pq)) {
        Node node = pop(&pq);
        int u = node.vertex;
        if (visited[u]) continue;
        visited[u] = 1;
        for (v = 0; v < n; v++) {
            if (adj[u][v] && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                push(&pq, v, dist[v]);
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    return 0;
}
