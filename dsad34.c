#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* push(Node* top, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    return newNode;
}

Node* pop(Node* top, int* value) {
    if (top == NULL) {
        printf("Stack underflow\n");
        exit(1);
    }
    *value = top->data;
    Node* temp = top;
    top = top->next;
    free(temp);
    return top;
}

int evaluatePostfix(char* expr) {
    Node* stack = NULL;
    char* token = strtok(expr, " ");
    while (token != NULL) {
        if (isdigit(token[0])) {
            stack = push(stack, atoi(token));
        } else {
            int val1, val2;
            stack = pop(stack, &val1);
            stack = pop(stack, &val2);
            switch (token[0]) {
                case '+': stack = push(stack, val2 + val1); break;
                case '-': stack = push(stack, val2 - val1); break;
                case '*': stack = push(stack, val2 * val1); break;
                case '/': stack = push(stack, val2 / val1); break;
            }
        }
        token = strtok(NULL, " ");
    }
    int result;
    stack = pop(stack, &result);
    return result;
}

int main() {
    char expr[100];
    fgets(expr, sizeof(expr), stdin);
    expr[strcspn(expr, "\n")] = '\0';
    printf("%d\n", evaluatePostfix(expr));
    return 0;
}