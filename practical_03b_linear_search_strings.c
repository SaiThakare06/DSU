/*
 * Practical No. 3b:
 * Title: Write a 'C' Program to Search a Particular Data from the Given Array of Strings using Linear Search Method
 *
 * Algorithm:
 * - Sequentially compare target string with each string in the array using strcmp().
 * - If strcmp(arr[i], key) == 0, the string matches.
 */

#include <stdio.h>
#include <string.h>

int main() {
    char str_arr[50][100];
    char key[100];
    int n, i, found = 0;

    printf("================ LINEAR SEARCH ON STRINGS ================\n");
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

    printf("\nEnter the string to search: ");
    scanf("%99s", key);

    // Linear Search for strings
    for (i = 0; i < n; i++) {
        if (strcmp(str_arr[i], key) == 0) {
            printf("\nMatch Found!");
            printf("\nString \"%s\" found at index %d (Position %d).\n", key, i, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nResult: String \"%s\" Not Found in the list.\n", key);
    }

    return 0;
}
