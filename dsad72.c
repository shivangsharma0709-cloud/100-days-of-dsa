#include <stdio.h>
#include <string.h>

int main() {
    char s[100005];
    if (scanf("%s", s) != 1) return 0;

    int visited[256] = {0};
    char result = '\0';

    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char val = (unsigned char)s[i];
        if (visited[val] == 1) {
            result = s[i];
            break;
        }
        visited[val] = 1;
    }

    if (result != '\0') {
        printf("%c\n", result);
    } else {
        printf("-1\n");
    }

    return 0;
}