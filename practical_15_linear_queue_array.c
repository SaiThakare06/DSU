/*
 * Practical No. 15:
 * Title: Write a C Program to Perform INSERT and DELETE Operations on Linear Queue Using Array
 *
 * Theory:
 * - Queue follows FIFO (First In First Out) principle.
 * - Insertion (Enqueue) occurs at REAR end.
 * - Deletion (Dequeue) occurs at FRONT end.
 * - Overflow condition: rear == MAX - 1
 * - Underflow condition: front == -1
 */

#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert more elements.\n");
        return;
    }

    printf("Enter Element to Insert: ");
    scanf("%d", &item);

    if (front == -1) {
        front = 0; // First element being inserted
    }
    rear++;
    queue[rear] = item;
    printf("Inserted %d into queue (FRONT = %d, REAR = %d).\n", item, front, rear);
}

void delete_element() {
    if (front == -1) {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }

    printf("\nDeleted Element = %d\n", queue[front]);

    // If only one element was left, reset queue
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("\nQueue is Empty.\n");
        return;
    }

    printf("\nQueue Elements (FRONT to REAR):\n");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int ch;

    do {
        printf("\n======= LINEAR QUEUE OPERATIONS (ARRAY) =======");
        printf("\n1. Insert (Enqueue)");
        printf("\n2. Delete (Dequeue)");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter Choice (1-4): ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delete_element();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid Choice! Please enter 1-4.\n");
        }
    } while (ch != 4);

    return 0;
}
