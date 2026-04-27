#include <stdio.h>
#include <string.h>

#define MAX_CHAR 256

char firstNonRepeating(char *s) {
    int count[MAX_CHAR] = {0};
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        count[(unsigned char)s[i]]++;
    }

    for (i = 0; s[i] != '\0'; i++) {
        if (count[(unsigned char)s[i]] == 1) {
            return s[i];
        }
    }

    return '$';
}

int main() {
    char s[100001];
    if (scanf("%s", s) == 1) {
        printf("%c\n", firstNonRepeating(s));
    }
    return 0;
}