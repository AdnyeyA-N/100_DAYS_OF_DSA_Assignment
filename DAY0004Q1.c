/*

Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays

*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int *arr = (int*)malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int start = 0;
        int end = n - 1;
        int temp;

        while (start < end) {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }

        for (int i = 0; i < n; i++) {
            printf("%d%s", arr[i], (i == n - 1 ? "" : " "));
        }
        
        free(arr);
    }
    return 0;
}