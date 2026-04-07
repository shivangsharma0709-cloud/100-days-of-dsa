#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) return i;
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int start, int end, int *preIndex) {
    if (start > end) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = preorder[*preIndex];
    node->left = node->right = NULL;
    (*preIndex)++;
    if (start == end) return node;
    int inIndex = search(inorder, start, end, node->data);
    node->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);
    return node;
}

void printPostorder(struct Node* node) {
    if (node == NULL) return;
    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->data);
}

int main() {
    int N;
    scanf("%d", &N);
    int preorder[N], inorder[N];
    for (int i = 0; i < N; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < N; i++) scanf("%d", &inorder[i]);
    int preIndex = 0;
    struct Node* root = buildTree(preorder, inorder, 0, N - 1, &preIndex);
    printPostorder(root);
    return 0;
}