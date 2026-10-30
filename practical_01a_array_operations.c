/*
 * Practical No. 1a:
 * Title: Write a 'C' Program to Perform Array Operations: Create, Insert, Delete, Display
 */

#include <stdio.h>

#define MAX 50

int arr[MAX];
int n = 0; // Current number of elements in array

// Function to create array by taking inputs from user
void create() {
    int i;
    printf("\nEnter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    if (n < 0 || n > MAX) {
        printf("Invalid size! Setting size to 0.\n");
        n = 0;
        return;
    }

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element [%d]: ", i);
        scanf("%d", &arr[i]);
    }
    printf("Array created successfully!\n");
}

// Function to insert an element at a given position (1-based position)
void insert() {
    int pos, element, i;

    if (n >= MAX) {
        printf("\nArray Overflow! Cannot insert more elements.\n");
        return;
    }

    printf("\nEnter position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Valid range is 1 to %d.\n", n + 1);
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &element);

    // Shift elements to the right to make space
    for (i = n - 1; i >= pos - 1; i--) {
        arr[i + 1] = arr[i];
    }

    // Insert new element
    arr[pos - 1] = element;
    n++;

    printf("Element %d inserted successfully at position %d.\n", element, pos);
}

// Function to delete an element from a given position (1-based position)
void delete_element() {
    int pos, item, i;

    if (n <= 0) {
        printf("\nArray Underflow! Array is empty.\n");
        return;
    }

    printf("\nEnter position to delete (1 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 1 || pos > n) {
        printf("Invalid position! Valid range is 1 to %d.\n", n);
        return;
    }

    item = arr[pos - 1];

    // Shift elements to the left to fill the gap
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
    printf("Deleted element = %d from position %d.\n", item, pos);
}

// Function to display the elements of the array
void display() {
    int i;
    if (n <= 0) {
        printf("\nArray is empty.\n");
        return;
    }

    printf("\nArray Elements (%d total):\n", n);
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\n--- ARRAY OPERATIONS MENU ---");
        printf("\n1. Create Array");
        printf("\n2. Insert Element");
        printf("\n3. Delete Element");
        printf("\n4. Display Array");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;
            case 2:
                insert();
                break;
            case 3:
                delete_element();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please select between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
