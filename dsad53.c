#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    if (data == -1) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Queue {
    struct Node* node;
    int hd;
    struct Queue* next;
};

void enqueue(struct Queue** front, struct Queue** rear, struct Node* node, int hd) {
    struct Queue* temp = (struct Queue*)malloc(sizeof(struct Queue));
    temp->node = node;
    temp->hd = hd;
    temp->next = NULL;
    if (*rear) (*rear)->next = temp;
    else *front = temp;
    *rear = temp;
}

struct Queue* dequeue(struct Queue** front) {
    if (!*front) return NULL;
    struct Queue* temp = *front;
    *front = (*front)->next;
    return temp;
}

struct List {
    int data;
    struct List* next;
};

void addToList(struct List** arr, int hd, int data, int offset) {
    struct List* temp = (struct List*)malloc(sizeof(struct List));
    temp->data = data;
    temp->next = NULL;
    if (!arr[hd + offset]) arr[hd + offset] = temp;
    else {
        struct List* cur = arr[hd + offset];
        while (cur->next) cur = cur->next;
        cur->next = temp;
    }
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root, 0);
    int i = 1;
    while (front && i < n) {
        struct Queue* q = dequeue(&front);
        struct Node* node = q->node;
        free(q);
        if (arr[i] != -1) {
            node->left = newNode(arr[i]);
            enqueue(&front, &rear, node->left, 0);
        }
        i++;
        if (i < n && arr[i] != -1) {
            node->right = newNode(arr[i]);
            enqueue(&front, &rear, node->right, 0);
        }
        i++;
    }
    return root;
}

void verticalOrder(struct Node* root, int n) {
    if (!root) return;
    int offset = n;
    struct List** arr = (struct List**)calloc(2*n+1, sizeof(struct List*));
    struct Queue *front = NULL, *rear = NULL;
    enqueue(&front, &rear, root, 0);
    while (front) {
        struct Queue* q = dequeue(&front);
        struct Node* node = q->node;
        int hd = q->hd;
        free(q);
        addToList(arr, hd, node->data, offset);
        if (node->left) enqueue(&front, &rear, node->left, hd-1);
        if (node->right) enqueue(&front, &rear, node->right, hd+1);
    }
    for (int i = 0; i < 2*n+1; i++) {
        struct List* cur = arr[i];
        if (cur) {
            while (cur) {
                printf("%d ", cur->data);
                cur = cur->next;
            }
            printf("\n");
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    verticalOrder(root, n);
    return 0;
}