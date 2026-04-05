#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

int isMirror(struct Node* t1, struct Node* t2) {
    if (!t1 && !t2) return 1;
    if (!t1 || !t2) return 0;
    return (t1->data == t2->data) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int isSymmetric(struct Node* root) {
    if (!root) return 1;
    return isMirror(root->left, root->right);
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) nodes[i] = newNode(arr[i]);
    for (int i = 0, j = 1; j < n; i++) {
        if (nodes[i]) {
            if (j < n) nodes[i]->left = nodes[j++];
            if (j < n) nodes[i]->right = nodes[j++];
        }
    }
    struct Node* root = nodes[0];
    free(nodes);
    return root;
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, N);
    if (isSymmetric(root)) printf("YES\n");
    else printf("NO\n");
    return 0;
}