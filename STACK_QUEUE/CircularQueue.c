#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int Q[MAX];
void insert();
void delete();
void display();
int start=-1,end=-1;
int main()
{
	int n,el;
	printf("MENU\n");
	printf("enter 1 to insert element \n");
	printf("enter 2 to delete element \n");
	printf("enter 3 to display\n");
	printf("enter 4 to exit\n");

	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				printf("Enter the element to insert: ");
        		scanf("%d", &el);
				insert(el);
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
				printf(" choiceEnter a valid choice\n");
		}
	}
}
void insert(int el)
{
	if(start==-1 && end==-1)
    {
        start=end=0;
        Q[end]=el;
    }
    else if((end+1)%MAX==start)
    {
        printf("\nQueue is full");
    }
    else
    {
        end=(end+1)%MAX;
        Q[end]=el;
    }
}
void delete()
{
	if((start==-1)&&(end==-1))
    {
        printf("\nQueue underflow");
    }
 	else if(start==end)
	{
   		printf("\nThe deleted element is %d\n",Q[start]);
   		start=end=-1;
	}
	else
	{
    	printf("\nThe deleted element is %d\n",Q[start]);
   		start=(start+1)%MAX;
	}
}
void display()
{
  	int i=start;
    if(start==-1&&end==-1)
    {
        printf("\nQueue is empty..");
    }
    else
    {
        printf("\nElements in a Queue are :");
        while(i<=end)
        {
            printf("%d ",Q[i]);
            i=(i+1)%MAX;
		}
	}
 }

