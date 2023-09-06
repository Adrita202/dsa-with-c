#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int queue[MAX];
int start=-1,end=-1;
void insert();
void delete();
void display();
int r;
int main()
{
	int a,x;
	printf("MENU\n");
	printf("enter 1 to insert element \n");
	printf("enter 2 to delete element \n");
	printf("enter 3 to display\n");
	printf("enter 4 to exit\n");

	while(1)
	{
		printf("Enter a number : ");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("Enter the element to insert : ");
        		scanf("%d", &x);
				insert(x);
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("invalid choice \n");
		}
	}
}
void isfull()
{
	if((end+1)%MAX==start)
		return 1;
	return 0;
}
void isEmpty()
{
	if((end==-1)||(end<MAX-1&&start>end))
		return 1;
	return 0;
}
void insert(el)
{
	if(!isFull())
	{
		end=(end+1)%MAX;
		queue[end]=el;
	}
	else if(start==-1 && end==-1)
    {
        start=0;
        end=0;
        queue[end]=el;
    }
    else
		printf("Queue overflow");
}
void delete()
{
	if(!isEmpty())
	{
		int r;
		r=Q[start];
		if(start==end)
		{
			end=start=-1;
		}
		else
		{
			start=(start+1)%MAX;
		}
		printf("the deleted element is %d\n",r);
	}
	else
	{
		printf("The Queue is empty.");
	}
}
void display()
{
  	int i=start;
    if(isEmpty())
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nElements in a Queue are:\n");
        for(;i<=end;i++)
        {
        	printf("%d \n",Q[i]);
		}
	}
 }
 

