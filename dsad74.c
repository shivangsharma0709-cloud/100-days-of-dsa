#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1000

struct Candidate {
    char name[100];
    int votes;
};

int main() {
    int n;
    scanf("%d", &n);
    char temp[100];
    struct Candidate arr[MAX];
    int count = 0;

    for (int i = 0; i < n; i++) {
        scanf("%s", temp);
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(arr[j].name, temp) == 0) {
                arr[j].votes++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(arr[count].name, temp);
            arr[count].votes = 1;
            count++;
        }
    }

    int maxVotes = 0;
    char winner[100];
    for (int i = 0; i < count; i++) {
        if (arr[i].votes > maxVotes || 
           (arr[i].votes == maxVotes && strcmp(arr[i].name, winner) < 0)) {
            maxVotes = arr[i].votes;
            strcpy(winner, arr[i].name);
        }
    }

    printf("%s %d\n", winner, maxVotes);
    return 0;
}
