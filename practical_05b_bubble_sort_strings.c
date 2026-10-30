/*
 * Practical No. 5b:
 * Title: Write a 'C' Program to Sort an Array of Strings using Bubble Sort Method
 *
 * Concept:
 * - Compare adjacent strings using strcmp(str[j], str[j+1]).
 * - If strcmp() > 0, swap the strings using strcpy().
 * - Sorts strings into alphabetical (lexicographical) order.
 */

#include <stdio.h>
#include <string.h>

int main() {
    char str_arr[50][100];
    char temp[100];
    int n, i, j;

    printf("================ BUBBLE SORT ON STRINGS ================\n");
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

    // Bubble Sort on Strings
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (strcmp(str_arr[j], str_arr[j + 1]) > 0) {
                // Swap strings
                strcpy(temp, str_arr[j]);
                strcpy(str_arr[j], str_arr[j + 1]);
                strcpy(str_arr[j + 1], temp);
            }
        }
    }

    printf("\nSorted String List (Alphabetical Order):\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", str_arr[i]);
    }

    return 0;
}
