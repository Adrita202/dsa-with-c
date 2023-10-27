#include<stdio.h>
#include<stdlib.h>
struct node
{
	int priority;
	int data;
	struct node *link;
};
void insert(int,int);
void display();
struct node *front=NULL;
int main()
{
	int ch,data,priority;
	while(1)
	{
		printf("1.Insert\n");
		printf("2.Display\n");
		printf("3.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("Input the item value to be added in the queue: ");
			scanf("%d",&data);
			printf("Enter its priority: ");
			scanf("%d",&priority);
			insert(data, priority);
			break;
		case 2:
			display();
  			break;
		case 3:
			exit(0);
			break;
		case 4:
			printf("Wrong input");
		}
	}
}
void insert(int data,int priority)
{
	struct node *temp,*q;
	temp= (struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->priority=priority;
	if(front==NULL || priority < front -> priority)
	{
		temp->link=front;
		front=temp;
	}
	else
	{
		q=front;
		while(q->link!=NULL && q->link->priority<=priority)
		{
			q=q->link;
		}
		temp->link=q->link;
		q->link=temp;
	}
}
void display()
{
	struct node *temp;
	temp=front;
	if(front==NULL)
		printf("Queue underflow\n");
	else
	{
		printf("The queue is:\n");
		printf("priority      Item\n");
		while(temp!=NULL)
		{
			printf("%5d     %5d\n",temp->priority,temp->data);
			temp=temp->link;
		}
	}
}
