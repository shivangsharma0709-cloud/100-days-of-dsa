#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    if (val == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0) return NULL;
    struct Node* root = createNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        if (curr) {
            curr->left = createNode(arr[i++]);
            if (curr->left) queue[rear++] = curr->left;
            if (i < n) {
                curr->right = createNode(arr[i++]);
                if (curr->right) queue[rear++] = curr->right;
            }
        }
    }
    free(queue);
    return root;
}

void rightView(struct Node* root) {
    if (!root) return;
    struct Node** queue = (struct Node**)malloc(1000 * sizeof(struct Node*));
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        int size = rear - front;
        for (int i = 0; i < size; i++) {
            struct Node* curr = queue[front++];
            if (i == size - 1) printf("%d ", curr->data);
            if (curr->left) queue[rear++] = curr->left;
            if (curr->right) queue[rear++] = curr->right;
        }
    }
    free(queue);
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    rightView(root);
    return 0;
}