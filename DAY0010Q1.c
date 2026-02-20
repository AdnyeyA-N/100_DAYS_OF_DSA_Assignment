/*

Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards

*/

#include <stdio.h>

int main() {
    char buffer[1005]; 
    
    if (scanf("%1000s", buffer) < 1) return 0;

    char *p = buffer;
    char *q = buffer;

    while (*q != '\0') {
        q++;
    }
    q--; 

    int ok = 1;

    while (p < q) {
        if (*p != *q) {
            ok = 0;
            break;
        }
        p++;
        q--;
    }

    if (ok) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}



