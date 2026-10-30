/*
 * Practical No. 2b:
 * Title: Write a 'C' Program to Find Maximum AND Value Produced by Pairwise Elements of an Array
 *
 * Example:
 * Elements: 12 (1100), 10 (1010)
 * 12 & 10 = 8 (1000)
 */

#include <stdio.h>

int main() {
    int arr[100];
    int n, i, j;
    int max_and = 0;
    int best_first = 0, best_second = 0;

    printf("================ MAXIMUM PAIRWISE AND VALUE ================\n");
    printf("Enter number of elements in array (min 2): ");
    scanf("%d", &n);

    if (n < 2) {
        printf("Error: At least 2 elements are required to form a pair.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Initialize max_and with the first pair
    max_and = arr[0] & arr[1];
    best_first = arr[0];
    best_second = arr[1];

    // Check all pairs (arr[i], arr[j])
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int current_and = arr[i] & arr[j];
            if (current_and > max_and) {
                max_and = current_and;
                best_first = arr[i];
                best_second = arr[j];
            }
        }
    }

    printf("\n--- RESULT ---");
    printf("\nPair with maximum bitwise AND: (%d, %d)", best_first, best_second);
    printf("\nMaximum Pairwise AND Value = %d\n", max_and);

    return 0;
}
