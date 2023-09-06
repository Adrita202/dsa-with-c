#include <stdio.h>
#include <stdlib.h>

// Define the structure for a singly linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node before a specified element in the linked list
void insertBefore(struct Node** head, int target, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;

    // If the list is empty, make the new node the head
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }

    // If the target is the head, update the head
    if ((*head)->data == target) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;

    // Search for the target node and keep track of the previous node
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }

    // If the target node is found, insert the new node before it
    if (temp->next != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        // Target node not found, so insert at the end
        newNode->next = NULL;
        temp->next = newNode;
    }
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
    for (int i = 5; i > 0; i--) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    printf("Original Linked List: ");
    printList(head);

    int targetElement = 3;
    int newData = 6;
    insertBefore(&head, targetElement, newData);
    printf("Linked List after inserting %d before %d: ", newData, targetElement);
    printList(head);

    // Free the memory allocated for the linked list nodes
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }

    return 0;
}

