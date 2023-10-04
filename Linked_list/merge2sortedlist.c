#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;

};
struct node *start1,*start2,*start3;
struct node *temp,*t;
void create(struct node *start)
{
	int x=1;
 	start=NULL;
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


