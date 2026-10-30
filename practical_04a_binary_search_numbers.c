/*
 * Practical No. 4a:
 * Title: Write a 'C' Program to Search a Particular Data from the Given Array of Numbers using Binary Search Method
 *
 * Requirements:
 * - The input array must be sorted in ascending order.
 * - Time Complexity: Best O(1), Average O(log n), Worst O(log n).
 */

#include <stdio.h>

int main() {
    int arr[100];
    int n, key, i;
    int low, high, mid, found = 0;

    printf("================ BINARY SEARCH ON NUMBERS ================\n");
    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d sorted elements (in ascending order):\n", n);
    for (i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the number to search: ");
    scanf("%d", &key);

    // Binary search logic
    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid] == key) {
            printf("\nMatch Found!");
            printf("\nElement %d found at index %d (Position %d).\n", key, mid, mid + 1);
            found = 1;
            break;
        } else if (key > arr[mid]) {
            low = mid + 1; // Search right half
        } else {
            high = mid - 1; // Search left half
        }
    }

    if (!found) {
        printf("\nResult: Element %d Not Found in the array.\n", key);
    }

    return 0;
}
