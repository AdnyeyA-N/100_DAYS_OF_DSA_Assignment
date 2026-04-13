/*

Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int size) {
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for (int i = 0; i < size; i++) {
        int val;
        scanf("%d", &val);
        
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        newNode->data = val;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    int n, m;
    
    if (scanf("%d", &n) != 1) return 1;
    struct Node* headA = createList(n);
    
    if (scanf("%d", &m) != 1) return 1;
    struct Node* headB = createList(m);

    struct Node* currA = headA;
    struct Node* currB = headB;

    if (n > m) {
        for (int i = 0; i < (n - m); i++) {
            currA = currA->next;
        }
    } else if (m > n) {
        for (int i = 0; i < (m - n); i++) {
            currB = currB->next;
        }
    }

    int intersectionFound = 0;
    int intersectionValue = 0;

    while (currA != NULL && currB != NULL) {
        if (currA->data == currB->data) {
            intersectionFound = 1;
            intersectionValue = currA->data;
            break; 
        }
        currA = currA->next;
        currB = currB->next;
    }

    if (intersectionFound) {
        printf("%d\n", intersectionValue);
    } else {
        printf("No Intersection\n");
    }

    freeList(headA);
    freeList(headB);

    return 0;
}