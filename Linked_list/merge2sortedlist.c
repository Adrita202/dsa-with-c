#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly-linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to insert a new node at the end of a linked list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to merge two sorted linked lists into a new sorted list
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    struct Node* mergedList = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data < list2->data) {
            insertAtEnd(&mergedList, list1->data);
            list1 = list1->next;
        } else {
            insertAtEnd(&mergedList, list2->data);
            list2 = list2->next;
        }
    }

    // If one of the lists is not empty, append the remaining elements
    while (list1 != NULL) {
        insertAtEnd(&mergedList, list1->data);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        insertAtEnd(&mergedList, list2->data);
        list2 = list2->next;
    }

    return mergedList;
}

// Function to print a linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    // Insert elements into the first sorted list
    insertAtEnd(&list1, 1);
    insertAtEnd(&list1, 3);
    insertAtEnd(&list1, 5);

    // Insert elements into the second sorted list
    insertAtEnd(&list2, 2);
    insertAtEnd(&list2, 4);
    insertAtEnd(&list2, 6);

    printf("List 1: ");
    printList(list1);
    printf("List 2: ");
    printList(list2);

    struct Node* mergedList = mergeSortedLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}

