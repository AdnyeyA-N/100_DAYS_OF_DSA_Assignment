/*

Problem: A system receives two separate logs of user arrival times from two different servers.
         Each log is already sorted in ascending order. Your task is to create a single 
         chronological log that preserves the correct order of arrivals.

Input:
- First line: integer p (number of entries in server log 1)
- Second line: p sorted integers representing arrival times from server 1
- Third line: integer q (number of entries in server log 2)
- Fourth line: q sorted integers representing arrival times from server 2)

Output:
- Print a single line containing all arrival times in chronological order, separated by spaces

Example:
Input:
5
10 20 30 50 70
4
15 25 40 60

Output:
10 15 20 25 30 40 50 60 70

Explanation: Compare the next unprocessed arrival time from both logs and append
             the earlier one to the final log until all entries are processed

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int p;
    if (scanf("%d", &p) != 1) return 0;
    
    int *log1 = (int*)malloc(p * sizeof(int));
    for (int k = 0; k < p; k++) {
        scanf("%d", &log1[k]);
    }

    int q;
    if (scanf("%d", &q) != 1) {
        free(log1);
        return 0;
    }

    int *log2 = (int*)malloc(q * sizeof(int));
    for (int k = 0; k < q; k++) {
        scanf("%d", &log2[k]);
    }

    int i = 0, j = 0;
    int first = 1;

    while (i < p && j < q) {
        if (!first) printf(" ");
        
        if (log1[i] < log2[j]) {
            printf("%d", log1[i]);
            i++;
        } else {
            printf("%d", log2[j]);
            j++;
        }
        first = 0;
    }

    while (i < p) {
        if (!first) printf(" ");
        printf("%d", log1[i]);
        i++;
        first = 0;
    }

    while (j < q) {
        if (!first) printf(" ");
        printf("%d", log2[j]);
        j++;
        first = 0;
    }

    printf("\n");

    free(log1);
    free(log2);
    return 0;
}