/*
 * Practical No. 5a:
 * Title: Write a 'C' Program to Sort an Array of Numbers using Bubble Sort Method
 *
 * Concept:
 * - Repeatedly compare adjacent elements and swap if arr[j] > arr[j+1].
 * - During each pass, the largest unsorted element "bubbles up" to its correct position.
 * - Time Complexity: Best O(n), Average O(n^2), Worst O(n^2).
 */

#include <stdio.h>

int main() {
    int arr[100];
    int n, i, j, temp;

    printf("================ BUBBLE SORT ON NUMBERS ================\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nOriginal Array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Bubble Sort Algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap adjacent elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Array (Ascending Order):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
