//impliment doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;
struct node *tail=NULL;
struct node *newnode,*temp,*t;
void insert_at_beg(int);
void insert_at_end(int);
void insert_at_anypos(int,int);
void delete_from_beg();
void delete_from_end();
void delete_at_anypos(int);
void create_dll();
void display();

int ch,el,x=1;

void main()
{
	//int ch,el,,x;
	int pos;
	printf("***MENU***\n");
	printf("1.CREATE a doubly linked list:\n");
	printf("2.Display a doubly linked list:\n");
	printf("3.Insert node at the begining:\n");
	printf("4.Insert node at the end:\n");
	printf("5.Insert node at any position:\n");
	
	printf("6.Delete node from beg:\n");
	printf("7.Delete node from end:\n");
	printf("8.Delete node from any position:\n");
	printf("9.Insert node after any element:\n");
	printf("10.Insert node before any element:\n");
	while(1)
	{
		printf("\n\tEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Creating a doubly linked list:\n");
				create_dll();
				printf("Displaying the list:\n");
				display();
				break;
			case 2:
				printf("Displaying the list:\n");
				display();
				break;
			case 3:
	   			printf("3.Inserting node at the begining:\n");
	   			printf("Enter the element: ");
	   			scanf("%d",&el);
	   			insert_at_beg(el);
	   			break;
	   		case 4:
	   			printf("3.Inserting node at the end:\n");
	   			printf("Enter the element: ");
	   			scanf("%d",&el);
	   			insert_at_end(el);
				break;
			case 5:
				printf("ENter the position where to insert:");
				scanf("%d",&pos);
				printf("Enter the element: ");
	   			scanf("%d",&el);
	   			insert_at_anypos(el,pos);
				break;
			case 6:
				printf("Deleting from begining:\n");
				delete_from_beg();
				break;
			case 7:
				printf("DEleting from end:\n");
				delete_from_end();
				break;
			case 8:
				printf("Enter the position you want to delete:\n");
				scanf("%d",&pos);
				delete_at_anypos(pos);
				break;
				
				
				
				
		}
	}
}
void create_dll()
{
	head=NULL;
	while(x)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data: ");
		scanf("%d",&el);
		newnode->data=el;
		newnode->next=NULL;
		newnode->prev=NULL;
		if(head==NULL)
			head=temp=newnode;
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;

		}
		printf("Enter 0 to stop or 1 to continue:");
  		scanf("%d",&x);
	}
}
void insert_at_beg(int el)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=el;
	newnode->prev=NULL;
	newnode->next=head;
	head=newnode;
	if(newnode->next!=NULL)
		newnode->next->prev=newnode;
}
void insert_at_end(int el)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=el;
	temp=head;
	while(temp->next!=NULL)
		temp=temp->next;
	newnode->prev=temp;
	newnode->next=NULL;
	temp->next=newnode;
}
void delete_from_beg()
{

	struct node *temp;
	if(head == NULL)
	{
		printf("list is empty");
	}
	else
	{
		temp =head;
		head= head->next;
		head->prev = NULL;
		free(temp);
	}
	printf("Node deleted");
}

void delete_from_end()
{
    if(head == NULL)
        printf("\n LIST IS EMPTY");
    else if(head->next==NULL)
	{
		t=head;
		head=NULL;
		free(t);
	}
    else
    {
    	while(temp->next->next!=NULL)
    	{
    		temp=temp->next;
		}
		t=temp->next;
		temp->next=NULL;
        free(t);
        printf("\nnode deleted\n");
    }
}
void delete_at_anypos(int pos)
{
	if(pos==0)
		printf("invalid position");
	else if(pos==1)
		delete_from_beg();
	else
	{
		temp = (struct node*)malloc(sizeof(struct node));
		int i=1;
		temp=head;
		while((i<pos-1) && (temp!=NULL))
		{
			temp=temp->next;
			i++;
		}
		if(temp==NULL)
		{
			printf("Invalid position");
		}
		else
		{
			t=temp->next;
			temp->next=t->next;
			t->next->prev=temp;
			free(t);
		}
	}
}
void display()
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
void insert_at_anypos(int el,int pos)
{
	int i;
	temp=head;
	if(pos<1)
		printf("Invalid position\n");
	else if(pos==1)
		insert_at_beg(el);
	else
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=el;
		while(i<pos-1 && temp != NULL)
		{
			temp=temp->next;
			i++;
		}
		if(temp==NULL)
			printf("Invalid position.");
		else
		{
			newnode->prev=temp;
			newnode->next=temp->next;
			temp->next->prev=newnode;
			temp->next=newnode;
		}
	}
}
