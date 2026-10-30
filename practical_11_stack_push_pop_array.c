/*
 * Practical No. 11:
 * Title: Write a C Program to Perform PUSH and POP Operations on Stack Using Array
 *
 * Theory:
 * - Stack is a linear data structure following LIFO (Last In First Out).
 * - All insertions and deletions take place at TOP end.
 * - Overflow condition: top == MAX - 1
 * - Underflow condition: top == -1
 */

#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push() {
    int item;
    if (top == MAX - 1) {
        printf("\nStack Overflow! Cannot push more elements.\n");
    } else {
        printf("\nEnter Element to Push: ");
        scanf("%d", &item);
        stack[++top] = item;
        printf("Pushed %d onto stack (TOP = %d).\n", item, top);
    }
}

void pop() {
    if (top == -1) {
        printf("\nStack Underflow! Stack is empty.\n");
    } else {
        printf("\nDeleted / Popped Element = %d (New TOP = %d)\n", stack[top--], top);
    }
}

void display() {
    int i;
    if (top == -1) {
        printf("\nStack is Empty.\n");
    } else {
        printf("\nStack Elements (from TOP to BOTTOM):\n");
        for (i = top; i >= 0; i--) {
            printf("| %4d |\n", stack[i]);
        }
        printf("+------+\n");
    }
}

int main() {
    int ch;

    do {
        printf("\n======= STACK OPERATIONS (ARRAY IMPLEMENTATION) =======");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter Choice (1-4): ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid Choice! Please enter 1-4.\n");
        }
    } while (ch != 4);

    return 0;
}
