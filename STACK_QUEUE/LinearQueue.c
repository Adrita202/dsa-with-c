#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void insert();
void delete();
void display();
int Q[MAX];
int end=-1;
int start=-1;
int main()
{

	printf("1.Insert element to queue \n");
    printf("2.Delete element from queue \n");
    printf("3.Display all elements of queue \n");
    printf("4.Quit \n");
    int choice;
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        int n;
        switch (choice)
        {
            case 1:
            	printf("Enter the element to insert: ");
            	scanf("%d",&n);
            	insert(n);
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
            printf("Wrong choice \n");
        }
    }
}
void insert(int el)
{

	if (isFull())
	{
		printf("Queue overflow");
		return;
	}
    if(start== -1)
    {
    	start=0;
    }
    Q[++end] = el;
}
int isFull()
{
	if(end==MAX-1)
		return 1;
	return 0;
}

void delete()
{
    if(!isEmpty())
    {
    	int r;
    	r=start++;
    	if(start>end)
    	{
    		start=-1;
    		end=-1;
		}
	}
	else
	{
		printf("The queue is empty\n");
	}
}
int isEmpty()
{
	if(end==-1)
	{
		return 1;
	}
	else
		return 0;
}


void display()
{
	int i;
	if(isEmpty())
	{
		printf("\nThe Queue is Empty ");
	}
	else
	{
		printf("Elements : ");
		for(i=start;i<=end;i++)
		{
			printf("%d  ",Q[i]);
		}
	}
}


