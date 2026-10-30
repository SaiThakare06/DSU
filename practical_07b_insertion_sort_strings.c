/*
 * Practical No. 7b:
 * Title: Write a 'C' Program to Sort an Array of Strings using Insertion Sort Method
 *
 * Concept:
 * - Insert each string into its correct sorted location among previous strings.
 * - Comparisons done using strcmp() and movements with strcpy().
 */

#include <stdio.h>
#include <string.h>

int main() {
    char str_arr[50][100];
    char key[100];
    int n, i, j;

    printf("================ INSERTION SORT ON STRINGS ================\n");
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

    // Insertion Sort for Strings
    for (i = 1; i < n; i++) {
        strcpy(key, str_arr[i]);
        j = i - 1;

        // Shift strings that are lexicographically greater than key
        while (j >= 0 && strcmp(str_arr[j], key) > 0) {
            strcpy(str_arr[j + 1], str_arr[j]);
            j = j - 1;
        }
        strcpy(str_arr[j + 1], key);
    }

    printf("\nSorted String List (Alphabetical Order):\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", str_arr[i]);
    }

    return 0;
}
