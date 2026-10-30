#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5 // Maximum size of the circular queue

int items[SIZE];
int front = -1;
int rear = -1;

// Check if the queue is full (Overflow Condition)
bool isFull() {
    if ((front == 0 && rear == SIZE - 1) || (front == rear + 1)) {
        return true;
    }
    return false;
}

// Check if the queue is empty (Underflow Condition)
bool isEmpty() {
    if (front == -1) {
        return true;
    }
    return false;
}

// Insert operation (Enqueue)
void insert(int element) {
    if (isFull()) {
        printf("\nQueue Overflow! Cannot insert %d.\n", element);
        return;
    }

    // First element insertion
    if (front == -1) {
        front = 0;
    }

    // Circularly increment rear
    rear = (rear + 1) % SIZE;
    items[rear] = element;
    printf("Inserted: %d\n", element);
}

// Delete operation (Dequeue)
void deleteElement() {
    if (isEmpty()) {
        printf("\nQueue Empty! Nothing to delete.\n");
        return;
    }

    int element = items[front];

    // Queue has only one element left
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        // Circularly increment front
        front = (front + 1) % SIZE;
    }
    printf("Deleted: %d\n", element);
}

// Display operation
void display() {
    if (isEmpty()) {
        printf("\nQueue is Empty.\n");
        return;
    }

    printf("\nQueue elements: ");
    int i = front;
    while (true) {
        printf("%d ", items[i]);
        if (i == rear) {
            break;
        }
        i = (i + 1) % SIZE; // Move circularly
    }
    printf("\nFront Index: %d, Rear Index: %d\n", front, rear);
}

int main() {
    int choice, value;

    printf("--- Circular Queue Simulation (C) ---");
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter integer to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                deleteElement();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please select 1-4.\n");
        }
    }
    return 0;
}
