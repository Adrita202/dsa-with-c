#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void push(int);
void pop();
void display();
struct node
{
	int data;
	struct node *link;

};
struct node * head=NULL;
struct node *temp;
int main()
{
	int c,el,temp;
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
				scanf("%d",&el);
				push(el);
				break;
			case 2:
				pop();
				printf("Item is popped");
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
	

//
//void delete_from_beg()
void pop()
{
	
	struct node *temp;
	temp= (struct node*)malloc(sizeof(struct node));
	temp=head;
	if(head==NULL)
		printf("LIst is empty");
	else
	{
		head=head->link;
		free(temp);
	}
}
void push(int el)
{
	struct node *temp;
	temp= (struct node*)malloc(sizeof(struct node));
	temp->data=el;
	temp->link=head;
	head=temp;
}

void display()
{
	struct node *t;
	t=head;
	while(t!= NULL)
    {
        printf("%d ",t->data);
        t = t->link;
    }
    printf("\n");
}
