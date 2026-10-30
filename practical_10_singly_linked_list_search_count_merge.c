/*
 * Practical No. 10:
 * Title: Write a C Program to Implement Singly Linked List with Operations:
 *        (i)   Search
 *        (ii)  Merge Two Lists
 *        (iii) Count the Nodes
 */

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Function to create a new node
struct node* createNode(int data) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a node at the end of a given list
struct node* insertEnd(struct node *head, int data) {
    struct node *newnode = createNode(data);
    if (head == NULL) {
        return newnode;
    }
    struct node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

// (i) Search operation
void search(struct node *head, int key) {
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
        printf("Element %d Not Found in the list.\n", key);
    }
}

// (ii) Count total nodes
int countNodes(struct node *head) {
    int count = 0;
    struct node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// (iii) Merge two linked lists
struct node* mergeLists(struct node *head1, struct node *head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }

    struct node *temp = head1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head2; // Connect last node of list 1 to first node of list 2

    return head1;
}

// Display function
void display(struct node *head, const char *list_name) {
    if (head == NULL) {
        printf("%s is empty.\n", list_name);
        return;
    }

    struct node *temp = head;
    printf("%s: ", list_name);
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *list1 = NULL;
    struct node *list2 = NULL;
    int choice, val, key;

    do {
        printf("\n======= SINGLY LINKED LIST: SEARCH, COUNT, MERGE =======");
        printf("\n1. Insert into List 1");
        printf("\n2. Insert into List 2");
        printf("\n3. Search in List 1");
        printf("\n4. Count Nodes in List 1 and List 2");
        printf("\n5. Display List 1 and List 2");
        printf("\n6. Merge List 2 into List 1");
        printf("\n7. Exit");
        printf("\nEnter choice (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert in List 1: ");
                scanf("%d", &val);
                list1 = insertEnd(list1, val);
                printf("Inserted into List 1.\n");
                break;

            case 2:
                printf("Enter value to insert in List 2: ");
                scanf("%d", &val);
                list2 = insertEnd(list2, val);
                printf("Inserted into List 2.\n");
                break;

            case 3:
                printf("Enter search key for List 1: ");
                scanf("%d", &key);
                search(list1, key);
                break;

            case 4:
                printf("Total nodes in List 1 = %d\n", countNodes(list1));
                printf("Total nodes in List 2 = %d\n", countNodes(list2));
                break;

            case 5:
                display(list1, "List 1");
                display(list2, "List 2");
                break;

            case 6:
                list1 = mergeLists(list1, list2);
                list2 = NULL; // List 2 is now merged into List 1
                printf("Lists merged successfully!\n");
                display(list1, "Merged List");
                break;

            case 7:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Enter 1-7.\n");
        }
    } while (choice != 7);

    return 0;
}
