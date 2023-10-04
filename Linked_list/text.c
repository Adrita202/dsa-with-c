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
struct node *new=NULL;
	if(head1->data<= head2->data)
	{
		head3->link=head1;
		head3=head1;
		head1=head3->link;
	}
	else
	{
		head3->link=head2;
		head3=head2;
		head2=head3->link;
	}
	new=head3;
	
	#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct node *newnode,*temp;
struct node *head1,*head2,*fhead,*ftail;
void create(struct node *head)
{
	int x=1;
 	head=NULL;
 	while(x)
 	{
		newnode=(struct node *)malloc(sizeof(struct node));
 		printf("\nEnter Data: ");
 		scanf("%d",&newnode->data);
 		newnode->link=NULL;
 		if(head==NULL)
 			temp=head=newnode;
	 	else
 		{
 			temp->link=newnode;
 			temp=newnode;
 		}
  		printf("Enter 0 to stop or 1 to continue\n");
  		scanf("%d",&x);
 	}
}
int main()
{
	printf("Enter the 1st sorted list:\n");
	create(head1);
	printf("displaying the list:\n");
	display(head1);
	printf("Enter the 2nd sorted list:\n");
	create(head2);
	printf("displaying the list:\n");
	display(head2);
	printf("merging the 2 lists:\n");
	merge();
	display();

}
struct node *merge(struct node *head1,struct node *head2)
{
	struct node *fhead=NULL;
	struct node *ftail=NULL;
	while(head1!=NULL && head2!=NULL)
	{
		if(fhead==NULL && ftail==NULL)
		{
			if(head1->data>head2->data)
			{
				fhead=head2;
				ftail=head2;
				head2=head2->link;
			}
			else
			{
				fhead=head1;
				ftail=head1;
				head1=head1->link;
			}
		}
		if(head1->data<head2->data)
		{
			ftail->link=head1;
			ftail=ftail->link;
			head1=head1->link;
		}
		else
		{
			ftail->link=head2;
			ftail=ftail->link;
			head2=head2->link;

		}
	}
	if(head1!=NULL)
		ftail->link=head1;
	if(head2!=NULL)
		ftail->link=head2;
	return fhead;
}
void display(struct node *fhead)
{
	struct node *t;
	t=fhead;
	while(t!= NULL)
    {
        printf("%d --> ",t->data);
        t = t->link;
    }
    printf("NULL");
}

