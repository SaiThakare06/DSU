/*
 * Practical No. 3a:
 * Title: Write a 'C' Program to Search a Particular Data from the Given Array of Numbers using Linear Search Method
 *
 * Algorithm:
 * - Sequentially check each element of the array from index 0 to n-1.
 * - Time Complexity: Best O(1), Worst O(n), Average O(n).
 */

#include <stdio.h>

int main() {
    int arr[100];
    int n, key, i, found = 0;

    printf("================ LINEAR SEARCH ON NUMBERS ================\n");
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

    printf("\nEnter the number to search (Search Key): ");
    scanf("%d", &key);

    // Linear Search traversal
    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("\nMatch Found!");
            printf("\nElement %d found at index %d (Position %d).\n", key, i, i + 1);
            found = 1;
            break; // Stop after finding the first occurrence
        }
    }

    if (!found) {
        printf("\nResult: Element %d Not Found in the array.\n", key);
    }

    return 0;
}
