/*
 * Practical No. 13:
 * Title: Write a C Program to Perform:
 *        (i)  Multiplication of Two Numbers Using Recursion
 *        (ii) Print Given String in Reverse Using Recursion
 */

#include <stdio.h>

// (i) Recursive Multiplication Function
// a * b = a + a + ... (b times)
int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    if (b > 0) {
        return a + multiply(a, b - 1);
    }
    // For negative multiplier b
    return -multiply(a, -b);
}

// (ii) Recursive String Reverse Print Function
void reverseString(char str[]) {
    if (str[0] == '\0') {
        return; // Base case: reached end of string
    }
    // Recursive step: process rest of string first
    reverseString(str + 1);
    // Print current character on unwinding
    printf("%c", str[0]);
}

int main() {
    int choice;
    int a, b, prod;
    char str[100];

    do {
        printf("\n================ RECURSION PRACTICAL ================");
        printf("\n1. Multiplication of Two Numbers Using Recursion");
        printf("\n2. Print Given String in Reverse Using Recursion");
        printf("\n3. Exit");
        printf("\nEnter Choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n--- PART A: MULTIPLICATION USING RECURSION ---");
                printf("\nEnter First Number (a): ");
                scanf("%d", &a);
                printf("Enter Second Number (b): ");
                scanf("%d", &b);
                prod = multiply(a, b);
                printf("Result: %d x %d = %d\n", a, b, prod);
                break;

            case 2:
                printf("\n--- PART B: STRING REVERSE USING RECURSION ---");
                printf("\nEnter String (e.g. DATA): ");
                scanf("%99s", str);
                printf("Reverse String = ");
                reverseString(str);
                printf("\n");
                break;

            case 3:
                printf("\nExiting program.\n");
                break;

            default:
                printf("\nInvalid Choice! Please enter 1-3.\n");
        }
    } while (choice != 3);

    return 0;
}
