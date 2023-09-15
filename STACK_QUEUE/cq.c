#include<stdio.h>
#define max 5
int queue[max],front=-1,rear=-1;
void insert();
void deletee();
void display();
int main()
{
	int a,x;
	printf("enter 1 to insert element \n");
	printf("enter 2 to delete element \n");
	printf("enter 3 to display\n");
	printf("enter 4 to exit\n");

	while(1)
	{
		printf("\nenter a number : ");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				insert();
				break;
			case 2:
				deletee();
				break;
			case 3:
				display();
				break;
			default:
				printf("invalid choice \n");


		}
	}
}
int isFull()
{
	if ((rear+1)%max==front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void insert()
{
	int element;
	if(isFull())
	{
		printf("\nthe queue is full.");
	}
   	else
   	{
   		printf("enter the element to insert : ");
   		scanf("%d",&element);
   		if((front==-1) && (rear==-1))
	   	{
		   	front=0;
	        rear=0;
	        queue[rear]=element;
	    }
	    else
	    {
	        rear=(rear+1)%max;
	        queue[rear]=element;
	    }
	}

}
void deletee()
{
	if((front==-1) && (rear==-1))
    {
        printf("\nQueue is underflow..");
    }
 	else if(front==rear)
	{
   		printf("\nThe dequeued element is %d", queue[front]);
   		front=-1;
   		rear=-1;
	}
	else
	{
    	printf("\nThe dequeued element is %d", queue[front]);
   		front=(front+1)%max;
	}
}
void display()
{
  	int i;
	i = front;
	if(front==-1 && rear == -1)
	{
		printf("\nqueue is empty.");
	}
	else
	{
		printf("the queue is : ");
		while(i!=rear)
		{
			printf("%d ,",queue[i]);
			i=(i+1)%max;
		}
		printf("%d",queue[rear]);
	}
}
