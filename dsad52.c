#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* newNode(int val) {
    if (val == -1) return NULL;
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    Node* nodes[n];
    for (int i = 0; i < n; i++) nodes[i] = newNode(arr[i]);
    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i]) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }
    return nodes[0];
}

Node* LCA(Node* root, int n1, int n2) {
    if (!root) return NULL;
    if (root->data == n1 || root->data == n2) return root;
    Node* left = LCA(root->left, n1, n2);
    Node* right = LCA(root->right, n1, n2);
    if (left && right) return root;
    return left ? left : right;
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    int n1, n2;
    scanf("%d %d", &n1, &n2);
    Node* root = buildTree(arr, N);
    Node* lca = LCA(root, n1, n2);
    if (lca) printf("%d\n", lca->data);
    return 0;
}