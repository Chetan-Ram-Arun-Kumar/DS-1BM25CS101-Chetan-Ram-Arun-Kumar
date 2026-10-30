#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// 1. Insertion at beginning
void insertBeginning() {
    int value;
    struct node *newnode;

    newnode = malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

// 2. Insertion at end
void insertEnd() {
    int value;
    struct node *newnode, *temp;

    newnode = malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
}

// 3. Insertion at specific position
void insertPosition() {
    int value, pos, i;
    struct node *newnode, *temp;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insertBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newnode = malloc(sizeof(struct node));

    printf("Enter value: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = temp->next;
    temp->next = newnode;
}

// 4. Deletion from beginning
void deleteBeginning() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

// 5. Deletion from end
void deleteEnd() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// 6. Deletion from specific position
void deletePosition() {
    int pos, i;
    struct node *temp, *prev;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || head == NULL) {
        printf("Invalid position or empty list\n");
        return;
    }

    if (pos == 1) {
        deleteBeginning();
        return;
    }

    temp = head;

    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display linked list
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert Beginning");
        printf("\n2. Insert End");
        printf("\n3. Insert Position");
        printf("\n4. Delete Beginning");
        printf("\n5. Delete End");
        printf("\n6. Delete Position");
        printf("\n7. Display");
        printf("\n8. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: insertPosition(); break;
            case 4: deleteBeginning(); break;
            case 5: deleteEnd(); break;
            case 6: deletePosition(); break;
            case 7: display(); break;
            case 8: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
