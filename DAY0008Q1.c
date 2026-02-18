/*

Problem: Given integers a and b, compute a^b using recursion without using pow() function.

Input:
- Two space-separated integers a and b

Output:
- Print a raised to power b

Example:
Input:
2 5

Output:
32

Explanation: 2^5 = 2 * 2 * 2 * 2 * 2 = 32

*/

#include <stdio.h>

double power(int base, int exp) {
    if (exp == 0) {
        return 1.0;
    } else if (exp > 0) {
        return base * power(base, exp - 1);
    } else {
        return (1.0 / base) * power(base, exp + 1);
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lf", power(a, b));
    return 0;
}