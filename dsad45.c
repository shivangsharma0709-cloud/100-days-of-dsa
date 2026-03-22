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

int height(struct Node* root) {
    if (root == NULL) return 0;
    int lh = height(root->left);
    int rh = height(root->right);
    return (lh > rh ? lh : rh) + 1;
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    struct Node* nodes[N];
    for (int i = 0; i < N; i++) nodes[i] = newNode(arr[i]);

    for (int i = 0, j = 1; j < N; i++) {
        if (nodes[i] != NULL) {
            if (j < N) nodes[i]->left = nodes[j++];
            if (j < N) nodes[i]->right = nodes[j++];
        }
    }

    printf("%d\n", height(nodes[0]));
    return 0;
}