#include <stdio.h>
#include <stdlib.h>

// Define a structure for a singly-linked list node
struct node {
    int data;
    struct node* link;
};
void create(struct node*);
void merge();
void display(struct node*);
struct node * head1=NULL;
struct node * head2=NULL;
struct node * temp,*temp2,*newnode;

// Function to insert a new node at the end of a linked list
//void insertAtEnd(struct node** head, int data) {
//    struct node* newNode = (struct node*)malloc(sizeof(struct node));
//    newNode->data = data;
//    newNode->link = NULL;
//
//    if (*head == NULL) {
//        *head = newNode;
//    } else {
//        struct node* current = *head;
//        while (current->link != NULL) {
//            current = current->link;
//        }
//        current->link = newNode;
//    }
//}

// Function to merge two linked lists into one
struct node* mergeLists(struct node* list1, struct node* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct node* current = list1;
    while (current->link != NULL) {
        current = current->link;
    }
    current->link = list2;

    return list1;
}

// Function to print a linked list
//void printList(struct node* head) {
//    struct node* current = head;
//    while (current != NULL) {
//        printf("%d -> ", current->data);
//        current = current->link;
//    }
//    printf("NULL\n");
//}

int main() {
    struct node* list1 = NULL;
    struct node* list2 = NULL;
    int num1, num2;
    int n1, n2,i;

    printf("Enter the  first list:\n");
    create(head1);


    printf("Enter  the second list:\n");
    create(head2);

    printf("List 1:\n");
    display(head1);
    //printList(list1);
    printf("List 2:\n");
    //printList(list2);
    display(head2);

    struct node* mergedList = mergeLists(list1, list2);

    printf("Merged List: ");
    //printList(mergedList);
	display(mergedList);
    return 0;
}
void create(head)
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
void display(int)
{
	struct node *t;
	t=head;
	while(t!= NULL)
    {
        printf("%d --> ",t->data);
        t = t->link;
    }
    printf("NULL");
}
