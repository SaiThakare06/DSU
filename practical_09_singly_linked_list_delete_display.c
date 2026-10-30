/*
 * Practical No. 9:
 * Title: Write a C Program to Implement Singly Linked List with Operations:
 *        (i)   Delete at Beginning
 *        (ii)  Delete at End
 *        (iii) Delete After
 *        (iv)  Display
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Helper function to insert at end so the list can be populated
void insertEnd(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Inserted %d into the list.\n", data);
}

// (i) Delete at Beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    struct node *temp = head;
    int deleted_val = temp->data;
    head = head->next;
    free(temp);

    printf("Deleted %d from beginning.\n", deleted_val);
}

// (ii) Delete at End
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }

    // Single node case
    if (head->next == NULL) {
        int deleted_val = head->data;
        free(head);
        head = NULL;
        printf("Deleted %d from end (list is now empty).\n", deleted_val);
        return;
    }

    // Traverse to second last node
    struct node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    int deleted_val = temp->next->data;
    free(temp->next);
    temp->next = NULL;

    printf("Deleted %d from end.\n", deleted_val);
}

// (iii) Delete After a given node
void deleteAfter(int key) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = head;

    // Search for the node with value 'key'
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found in the list.\n", key);
    } else if (temp->next == NULL) {
        printf("There is no node after %d to delete.\n", key);
    } else {
        struct node *to_delete = temp->next;
        int deleted_val = to_delete->data;
        temp->next = to_delete->next;
        free(to_delete);
        printf("Deleted node %d which was after node %d.\n", deleted_val, key);
    }
}

// (iv) Display linked list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val, key;

    do {
        printf("\n======= SINGLY LINKED LIST (DELETION OPERATIONS) =======");
        printf("\n1. Insert Element (to build list)");
        printf("\n2. Delete at Beginning");
        printf("\n3. Delete at End");
        printf("\n4. Delete After a Node");
        printf("\n5. Display List");
        printf("\n6. Exit");
        printf("\nEnter choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 2:
                deleteBeginning();
                break;
            case 3:
                deleteEnd();
                break;
            case 4:
                printf("Enter node value after which deletion should happen: ");
                scanf("%d", &key);
                deleteAfter(key);
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please select 1-6.\n");
        }
    } while (choice != 6);

    return 0;
}
