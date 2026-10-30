/*
 * Practical No. 6a:
 * Title: Write a 'C' Program to Sort an Array of Numbers using Selection Sort Method
 *
 * Concept:
 * - Repeatedly select the minimum element from the unsorted portion of the array.
 * - Swap it with the element at the beginning of the unsorted portion.
 * - Time Complexity: Best O(n^2), Average O(n^2), Worst O(n^2).
 */

#include <stdio.h>

int main() {
    int arr[100];
    int n, i, j, min_idx, temp;

    printf("================ SELECTION SORT ON NUMBERS ================\n");
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

    // Selection Sort Algorithm
    for (i = 0; i < n - 1; i++) {
        // Assume current index i holds the minimum
        min_idx = i;

        // Search for the smallest element in the remaining unsorted part
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        // Swap the found minimum element with the element at index i
        if (min_idx != i) {
            temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }

    printf("\nSorted Array (Ascending Order):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
