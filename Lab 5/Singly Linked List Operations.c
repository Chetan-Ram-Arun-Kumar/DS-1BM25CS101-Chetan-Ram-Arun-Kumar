#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertEnd(struct Node** head, int data);
void display(struct Node* head);
void sortList(struct Node* head);
void reverseList(struct Node** head);
struct Node* concatenateLists(struct Node* head1, struct Node* head2);
int searchElement(struct Node* head, int key);
int countNodes(struct Node* head);

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* concatenatedList = NULL;
    int choice, data, key, pos;

    printf("--- Singly Linked List Operations ---\n");
    while (1) {
        printf("\n1. Insert into List 1\n");
        printf("2. Insert into List 2\n");
        printf("3. Sort List 1\n");
        printf("4. Reverse List 1\n");
        printf("5. Concatenate List 1 and List 2\n");
        printf("6. Search in List 1\n");
        printf("7. Count nodes in List 1\n");
        printf("8. Display lists\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert in List 1: ");
                scanf("%d", &data);
                insertEnd(&list1, data);
                break;
            case 2:
                printf("Enter data to insert in List 2: ");
                scanf("%d", &data);
                insertEnd(&list2, data);
                break;
            case 3:
                sortList(list1);
                printf("List 1 sorted successfully.\n");
                display(list1);
                break;
            case 4:
                reverseList(&list1);
                printf("List 1 reversed successfully.\n");
                display(list1);
                break;
            case 5:
                concatenatedList = concatenateLists(list1, list2);
                printf("Lists concatenated successfully.\n");
                printf("Concatenated ");
                display(concatenatedList);
                break;
            case 6:
                printf("Enter element to search in List 1: ");
                scanf("%d", &key);
                pos = searchElement(list1, key);
                if (pos != -1)
                    printf("Element %d found at node position %d.\n", key, pos);
                else
                    printf("Element %d not found in the list.\n", key);
                break;
            case 7:
                printf("Total number of nodes in List 1: %d\n", countNodes(list1));
                break;
            case 8:
                printf("List 1: ");
                display(list1);
                printf("List 2: ");
                display(list2);
                break;
            case 9:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// Helper function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Helper function to insert a node at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Helper function to display the list
void display(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 1. Sort the linked list (Bubble Sort approach swapping data)
void sortList(struct Node* head) {
    if (head == NULL || head->next == NULL) return;

    struct Node* i;
    struct Node* j;
    int temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// 2. Reverse the linked list (Iterative pointer manipulation)
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Store next node
        current->next = prev;  // Reverse current node's pointer
        prev = current;        // Move pointers one step forward
        current = next;
    }
    *head = prev;              // Update head to point to the new first node
}

// 3. Concatenation of two linked lists
struct Node* concatenateLists(struct Node* head1, struct Node* head2) {
    // If one list is empty, return the other
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* temp = head1;
    // Traverse to the end of the first list
    while (temp->next != NULL) {
        temp = temp->next;
    }
    // Link the last node of first list to the head of second list
    temp->next = head2;

    return head1;
}

// 4. Search for an element (Returns 1-based index position, or -1 if not found)
int searchElement(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

// 5. Count the number of nodes in Linked List
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}
