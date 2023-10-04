#include<stdio.h>
#include<string.h>
#define MAX 5
int isEmpty();
int isFULL();
void push(int);
int pop();
void display();
int top=-1;
int stk[MAX];
int main()
{
	int c,n,temp;
	while(1)
	{
		printf("\nEnter 1 to push an element");
		printf("\nEnter 2 to pop an element");
		printf("\nEnter 3 to display stack");
		printf("\nEnter 4 to exit\n");
		printf("\n\n Enter your choice: ");
		scanf("%d",&c);

		switch(c)
		{
			case 1:
				printf("Enter the element to push: ");
				scanf("%d",&n);
				push(n);
				break;
			case 2:
				temp=pop();
				if(temp!=-12345678)
					printf("%d is popped",temp);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
			default:
				printf("Invalid choice");
				
			}
		}
	}
	int isEmpty()
		return top==-1;
	int isFull()
	{
		return top==MAX-1;
	}
	void push( int e)
	{
		if(isFull())
			printf("Stack Overflow");
		else
			stk[++top]=e;
	}
	int pop()
	{
		int temp;
		if(isEmpty())
		{
			printf("Stack underflow");
			return -12345678;
		}
		else
			return stk[top--];
	}
	void display()
	{
		int i;
		printf("The current stack is:\n");
		for(i=top;i>=0;i--)
		{
			printf("%d",stk[i]);
		}
	}
