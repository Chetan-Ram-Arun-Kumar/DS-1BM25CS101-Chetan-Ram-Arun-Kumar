/* Lab Program 3a -
Write a program to simulate the working of a linear queue of integers using an array. Provide the following operations: Insert DeleteDisplay
The program should print appropriate messages for queue empty and queue overflow conditions */


#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Defined small size to easily demonstrate overflow

int queue[MAX];
int front = -1;
int rear = -1;

// Insert an element into the queue
void insert() {
    int item;
    if (rear == MAX - 1) {
        printf("\nQueue Overflow! Cannot insert more elements.\n");
        return;
    }

    printf("Enter the integer to insert: ");
    scanf("%d", &item);

    if (front == -1) { // Inserting the very first element
        front = 0;
    }

    rear++;
    queue[rear] = item;
    printf("%d inserted successfully.\n", item);
}

// Delete an element from the queue
void delete() {
    if (front == -1 || front > rear) {
        printf("\nQueue Underflow! Queue is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;

    // Reset queue pointers if the queue becomes completely empty
    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

// Display the elements of the queue
void display() {
    if (front == -1) {
        printf("\nQueue is Empty.\n");
        return;
    }

    printf("\nQueue elements are: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Linear Queue Operations ---");
        printf("\n1. Insert (Enqueue)");
        printf("\n2. Delete (Dequeue)");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert();
                    break;
            case 2: delete();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting program.\n");
                    exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
