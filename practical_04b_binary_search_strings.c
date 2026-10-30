/*
 * Practical No. 4b:
 * Title: Write a 'C' Program to Search a Particular Data from the Given Array of Strings using Binary Search Method
 *
 * Requirements:
 * - Strings must be provided in sorted (lexicographical / alphabetical) order.
 * - Comparisons performed using strcmp().
 */

#include <stdio.h>
#include <string.h>

int main() {
    char str_arr[50][100];
    char key[100];
    int n, i;
    int low, high, mid, found = 0;

    printf("================ BINARY SEARCH ON STRINGS ================\n");
    printf("Enter number of strings: ");
    scanf("%d", &n);

    if (n <= 0 || n > 50) {
        printf("Invalid number of strings.\n");
        return 1;
    }

    printf("Enter %d sorted strings in alphabetical order (e.g. Apple Banana Grapes Mango Orange):\n", n);
    for (i = 0; i < n; i++) {
        printf("String [%d]: ", i);
        scanf("%99s", str_arr[i]);
    }

    printf("\nEnter the string to search: ");
    scanf("%99s", key);

    low = 0;
    high = n - 1;

    while (low <= high) {
        mid = (low + high) / 2;
        int cmp = strcmp(key, str_arr[mid]);

        if (cmp == 0) {
            printf("\nMatch Found!");
            printf("\nString \"%s\" found at index %d (Position %d).\n", key, mid, mid + 1);
            found = 1;
            break;
        } else if (cmp > 0) {
            low = mid + 1; // Key is lexicographically greater -> search right
        } else {
            high = mid - 1; // Key is lexicographically smaller -> search left
        }
    }

    if (!found) {
        printf("\nResult: String \"%s\" Not Found in the list.\n", key);
    }

    return 0;
}
