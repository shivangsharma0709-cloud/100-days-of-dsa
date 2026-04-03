#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int countOccurrences(struct Node* head, int key) {
    int count = 0;
    while (head != NULL) {
        if (head->data == key) count++;
        head = head->next;
    }
    return count;
}

int main() {
    int n, key, i, val;
    scanf("%d", &n);
    struct Node* head = NULL;
    struct Node* temp = NULL;
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        struct Node* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }
    scanf("%d", &key);
    printf("%d\n", countOccurrences(head, key));
    return 0;
}