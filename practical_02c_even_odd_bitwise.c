/*
 * Practical No. 2c:
 * Title: Write a 'C' Program to Check Whether a Number is Even or Odd Using Bitwise Operator
 *
 * Theory:
 * - In binary, the least significant bit (LSB) of an even number is always 0.
 * - The LSB of an odd number is always 1.
 * - (Number & 1) == 0 -> Even Number
 * - (Number & 1) == 1 -> Odd Number
 */

#include <stdio.h>

int main() {
    int num;

    printf("================ EVEN OR ODD USING BITWISE OPERATOR ================\n");
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Using bitwise AND operator
    if ((num & 1) == 0) {
        printf("\nResult: %d is an EVEN number.\n", num);
        printf("Explanation: The least significant bit (LSB) of %d is 0.\n", num);
    } else {
        printf("\nResult: %d is an ODD number.\n", num);
        printf("Explanation: The least significant bit (LSB) of %d is 1.\n", num);
    }

    return 0;
}
