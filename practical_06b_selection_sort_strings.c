/*
 * Practical No. 6b:
 * Title: Write a 'C' Program to Sort an Array of Strings using Selection Sort Method
 *
 * Concept:
 * - In each pass i, find the lexicographically smallest string between i and n-1.
 * - Swap it with the string at position i.
 */

#include <stdio.h>
#include <string.h>

int main() {
    char str_arr[50][100];
    char temp[100];
    int n, i, j, min_idx;

    printf("================ SELECTION SORT ON STRINGS ================\n");
    printf("Enter number of strings: ");
    scanf("%d", &n);

    if (n <= 0 || n > 50) {
        printf("Invalid number of strings.\n");
        return 1;
    }

    printf("Enter %d strings:\n", n);
    for (i = 0; i < n; i++) {
        printf("String [%d]: ", i);
        scanf("%99s", str_arr[i]);
    }

    printf("\nOriginal String List:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", str_arr[i]);
    }

    // Selection Sort on Strings
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            // If str_arr[j] is lexicographically smaller than str_arr[min_idx]
            if (strcmp(str_arr[j], str_arr[min_idx]) < 0) {
                min_idx = j;
            }
        }

        // Swap the smallest string found with the string at position i
        if (min_idx != i) {
            strcpy(temp, str_arr[i]);
            strcpy(str_arr[i], str_arr[min_idx]);
            strcpy(str_arr[min_idx], temp);
        }
    }

    printf("\nSorted String List (Alphabetical Order):\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", str_arr[i]);
    }

    return 0;
}
