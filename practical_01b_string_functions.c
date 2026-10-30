/*
 * Practical No. 1b:
 * Title: Write a 'C' Program to implement various string functions like:
 *        strcmp, strlen, strcpy, strrev, strcat, strupr, strlwr, strchr
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Helper implementation of strrev (reverse a string)
char* custom_strrev(char *str) {
    int i = 0, j = strlen(str) - 1;
    char temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
    return str;
}

// Helper implementation of strupr (convert string to uppercase)
char* custom_strupr(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = (char)toupper((unsigned char)str[i]);
    }
    return str;
}

// Helper implementation of strlwr (convert string to lowercase)
char* custom_strlwr(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = (char)tolower((unsigned char)str[i]);
    }
    return str;
}

int main() {
    char str1[100], str2[100], temp[100];
    char ch;
    char *ptr;
    int choice, cmp_result;

    printf("Enter primary string (str1): ");
    scanf("%99s", str1);

    do {
        printf("\n================ STRING FUNCTIONS MENU ================");
        printf("\n1. strlen() - Find length of string");
        printf("\n2. strcmp() - Compare two strings");
        printf("\n3. strcpy() - Copy one string to another");
        printf("\n4. strcat() - Concatenate two strings");
        printf("\n5. strrev() - Reverse the string");
        printf("\n6. strupr() - Convert string to UPPERCASE");
        printf("\n7. strlwr() - Convert string to lowercase");
        printf("\n8. strchr() - Find first occurrence of character");
        printf("\n9. Re-enter primary string");
        printf("\n10. Exit");
        printf("\nEnter choice (1-10): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n[strlen] Length of \"%s\" = %lu\n", str1, (unsigned long)strlen(str1));
                break;

            case 2:
                printf("\nEnter second string to compare with: ");
                scanf("%99s", str2);
                cmp_result = strcmp(str1, str2);
                if (cmp_result == 0) {
                    printf("[strcmp] Strings are EQUAL (result = 0)\n");
                } else if (cmp_result < 0) {
                    printf("[strcmp] \"%s\" is smaller than \"%s\" (result = %d)\n", str1, str2, cmp_result);
                } else {
                    printf("[strcmp] \"%s\" is greater than \"%s\" (result = %d)\n", str1, str2, cmp_result);
                }
                break;

            case 3:
                strcpy(temp, str1);
                printf("\n[strcpy] Original string: %s\n", str1);
                printf("[strcpy] Copied into temp: %s\n", temp);
                break;

            case 4:
                printf("\nEnter second string to concatenate: ");
                scanf("%99s", str2);
                strcpy(temp, str1); // copy so str1 is preserved
                strcat(temp, str2);
                printf("[strcat] Concatenated result: %s\n", temp);
                break;

            case 5:
                strcpy(temp, str1);
                custom_strrev(temp);
                printf("\n[strrev] Original: %s\n", str1);
                printf("[strrev] Reversed: %s\n", temp);
                break;

            case 6:
                strcpy(temp, str1);
                custom_strupr(temp);
                printf("\n[strupr] Uppercase: %s\n", temp);
                break;

            case 7:
                strcpy(temp, str1);
                custom_strlwr(temp);
                printf("\n[strlwr] Lowercase: %s\n", temp);
                break;

            case 8:
                printf("\nEnter character to search in \"%s\": ", str1);
                scanf(" %c", &ch);
                ptr = strchr(str1, ch);
                if (ptr != NULL) {
                    printf("[strchr] Character '%c' found at index %ld (position %ld).\n", 
                           ch, (long)(ptr - str1), (long)(ptr - str1 + 1));
                } else {
                    printf("[strchr] Character '%c' not found in \"%s\".\n", ch, str1);
                }
                break;

            case 9:
                printf("\nEnter new primary string: ");
                scanf("%99s", str1);
                printf("Primary string updated to: %s\n", str1);
                break;

            case 10:
                printf("\nExiting. Thank you!\n");
                break;

            default:
                printf("\nInvalid option! Please enter 1-10.\n");
        }
    } while (choice != 10);

    return 0;
}
