#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *tail=NULL;
struct node *newnode;
void create();
void display();
void main()
{
	printf("Create a circular linked list:\n");
	create();
	printf("Display the list:\n");
	display();

}
void create()
{
	int x=1,el,ch;
	tail=NULL;
	while(x)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data: ");
		scanf("%d",&el);
		newnode->data=el;
		newnode->link=NULL;
		if(tail==NULL)
		{
			tail=newnode;
			tail->link=newnode;
		}
		else
		{
			newnode->link=tail->link;
			tail->link=newnode;
			tail=newnode;
		}
		printf("Enter 0 to stop or 1 to continue:");
  		scanf("%d",&x);
	}
}
void display()
{
	struct node *temp;
	if(tail==NULL)
		printf("The list is empty");
	else
	{
		temp=tail->link;
		while(temp->link!=tail->link)
		{
			printf("%d->",&temp->data);
			temp=temp->link;
		}
		printf("%d->",&temp->data);
	}
}

