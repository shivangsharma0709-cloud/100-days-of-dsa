#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return newNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    return root;
}

struct Node* LCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        if (n1 < root->data && n2 < root->data) root = root->left;
        else if (n1 > root->data && n2 > root->data) root = root->right;
        else return root;
    }
    return NULL;
}

int main() {
    int N, i, n1, n2;
    scanf("%d", &N);
    int arr[N];
    for (i = 0; i < N; i++) scanf("%d", &arr[i]);
    scanf("%d %d", &n1, &n2);
    struct Node* root = NULL;
    for (i = 0; i < N; i++) root = insert(root, arr[i]);
    struct Node* lca = LCA(root, n1, n2);
    if (lca != NULL) printf("%d\n", lca->data);
    return 0;
}