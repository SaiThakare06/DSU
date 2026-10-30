/*
 * Practical No. 7a:
 * Title: Write a 'C' Program to Sort an Array of Numbers using Insertion Sort Method
 *
 * Concept:
 * - Divides array into sorted and unsorted parts.
 * - Iteratively picks an element (key) and inserts it into its proper position in the sorted sub-array.
 * - Time Complexity: Best O(n), Average O(n^2), Worst O(n^2).
 */

#include <stdio.h>

int main() {
    int arr[100];
    int n, i, j, key;

    printf("================ INSERTION SORT ON NUMBERS ================\n");
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

    // Insertion Sort Algorithm
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    printf("\nSorted Array (Ascending Order):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
