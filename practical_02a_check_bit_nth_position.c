/*
 * Practical No. 2a:
 * Title: Write a 'C' Program for Checking a Bit at Nth Position (Set or Clear)
 *
 * Concept:
 * - A bit is SET if it is 1, and CLEAR if it is 0.
 * - To check the nth bit (0-indexed): Number & (1 << n)
 * - If result is non-zero, bit is SET.
 * - If result is 0, bit is CLEAR.
 */

#include <stdio.h>

void print_binary(int num) {
    int i;
    printf("Binary: ");
    for (i = 15; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" ");
    }
    printf("\n");
}

int main() {
    int number, n;

    printf("================ BIT CHECKING PROGRAM ================\n");
    printf("Enter an integer number: ");
    scanf("%d", &number);

    printf("Enter bit position to check (0 to 31, where 0 is LSB): ");
    scanf("%d", &n);

    if (n < 0 || n > 31) {
        printf("Error: Bit position must be between 0 and 31.\n");
        return 1;
    }

    printf("\nChecking status of bit at position %d for number %d:\n", n, number);
    print_binary(number);

    // Using bitwise AND with a mask
    if (number & (1 << n)) {
        printf("\nResult: The bit at position %d is SET (1).\n", n);
    } else {
        printf("\nResult: The bit at position %d is CLEAR (0).\n", n);
    }

    return 0;
}
