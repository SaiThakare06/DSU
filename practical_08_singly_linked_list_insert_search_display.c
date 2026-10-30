/*
 * Practical No. 8:
 * Title: Write a 'C' Program to Implement Singly Linked List with Operations:
 *        (i)   Insert at Beginning
 *        (ii)  Insert at End
 *        (iii) Insert After
 *        (iv)  Search
 *        (v)   Display
 */

#include <stdio.h>
#include <stdlib.h>

// Definition of Node structure
struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// Helper to create a new node
struct node* createNode(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// (i) Insert at Beginning
void insertBeginning(int data) {
    struct node *newnode = createNode(data);
    newnode->next = head;
    head = newnode;
    printf("Inserted %d at the beginning.\n", data);
}

// (ii) Insert at End
void insertEnd(int data) {
    struct node *newnode = createNode(data);
    if (head == NULL) {
        head = newnode;
    } else {
        struct node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
    printf("Inserted %d at the end.\n", data);
}

// (iii) Insert After a given key element
void insertAfter(int key, int data) {
    struct node *temp = head;

    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found in the list!\n", key);
    } else {
        struct node *newnode = createNode(data);
        newnode->next = temp->next;
        temp->next = newnode;
        printf("Inserted %d after node %d.\n", data, key);
    }
}

// (iv) Search for an element
void search(int key) {
    struct node *temp = head;
    int pos = 1;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("Element %d found at position %d.\n", key, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found) {
        printf("Element %d not found in the list.\n", key);
    }
}

// (v) Display linked list
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
        printf("\n======= SINGLY LINKED LIST (INSERTION & SEARCH) =======");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Insert After a Node");
        printf("\n4. Search Element");
        printf("\n5. Display List");
        printf("\n6. Exit");
        printf("\nEnter choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &val);
                insertBeginning(val);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            case 3:
                printf("Enter target node value after which to insert: ");
                scanf("%d", &key);
                printf("Enter new value to insert: ");
                scanf("%d", &val);
                insertAfter(key, val);
                break;
            case 4:
                printf("Enter element to search: ");
                scanf("%d", &key);
                search(key);
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
