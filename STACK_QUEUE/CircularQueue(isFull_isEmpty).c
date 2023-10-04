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
		printf("\nEnter your choice: ");
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
				printf("invalid choice \n");
		}
	}
}
int isFull()
{
	if((start==0 && end==MAX-1) || (start-1)==end )
		return 1;
	return 0;
}
void insert(el)
{
	if(!isFull())
	{
		if(start==-1)
			start = end = 0;
		else
			end=(end+1)%MAX;
		Q[end]=el;
	}
	else
		printf("Queue is full\n");
}
int isEmpty()
{
	if((end==-1)||(end<MAX-1&&start>end))
		return 1;
	return 0;
}
void delete()
{
	if(!isEmpty())
	{
		int r;
		r=Q[start];
		if(start==end)
			end=start=-1;
		else
			start=(start+1)%MAX;
		printf("the deleted element is %d\n",r);
	}
	else
		printf("The Queue is empty.");
}
//void display()
//{
//	int i;
//    if (isEmpty())
//		printf("Queue is empty.\n");
//    else
//    {
//        printf("\nElements in a Queue are :");
//        while(i<=end)
//        {
//            printf("%d,",Q[i]);
//            i=(i+1)%MAX;
//		}
//	}
//}
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
        if(start<end)
        {
        	for(i=start;i<=end;i++)
				printf("%d\t",Q[i]);
		}
        else
        {
        	for(i=start;i<MAX;i++)
				printf("%d\t",Q[i]);
			for(i=start;i<=end;i++)
				printf("%d\t",Q[i]);
		}

	}
 }


