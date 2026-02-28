/*

Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.

Input:
- First line: integer n
- Second line: n integers

Output:
- Print the count of subarrays having sum zero

Example:
Input:
6
1 -1 2 -2 3 -3

Output:
6

Explanation: A subarray is a continuous part of the array. 
             For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero:
             [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. 
             Since there are 6 such subarrays, the output is 6.


*/

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    long val_a = *(long*)a;
    long val_b = *(long*)b;
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 1;

    long *prefix_sums = (long *)malloc((n + 1) * sizeof(long));
    prefix_sums[0] = 0;
    
    long current_sum = 0;
    for (int i = 1; i <= n; i++) {
        int val;
        scanf("%d", &val);
        current_sum += val;
        prefix_sums[i] = current_sum;
    }

    qsort(prefix_sums, n + 1, sizeof(long), compare);

    long count = 0;
    long current_streak = 1;

    for (int i = 1; i <= n; i++) {
        if (prefix_sums[i] == prefix_sums[i - 1]) {
            current_streak++;
        } else {
            count += (current_streak * (current_streak - 1)) / 2;
            current_streak = 1;
        }
    }
    count += (current_streak * (current_streak - 1)) / 2;

    printf("%ld\n", count);

    free(prefix_sums);
    return 0;
}