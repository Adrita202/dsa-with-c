#include<stdio.h>
#include<stdlib.h>
void create();
void frequency(int);
void sort();
void search(int);
void display();
void reverse();
struct node
{
	int data;
	struct node *link;

};
struct node * head=NULL;
struct node *newnode,*temp,*t;
int main()
{
	printf("Enter 1 to create a linked list:\n");
	printf("Enter 2 to find frequency:\n");
	printf("Enter 3 to sort the list:\n");
	printf("Enter 4 to display:\n");
	printf("Enter 5 to search any element:\n");
	printf("Enter 6 to reverse the list:\n");
	int ch,el,pos;
	while (1)
    {
        printf("\n  Enter your choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
        	case 1:
				printf("CREATING LIST\n");
				create();
				break;
        	case 2:
				printf("\nEnter the element you want to find frequency: ");
				scanf("%d",&el);
				frequency(el);
				break;
   			case 3:
   				sort();
   				display();
   				break;
   	
   			case 4:
   				display();
   				break;
   			case 5:
				printf("Enter the element to search: ");
				scanf("%d",&el);
				search(el);
				break;
			case 6:
				printf("REversed list\n");
				reverse();
				display();
				break;
				
			default:
				printf("wrong input!");
		}
	}
}
void create()
{
	int x=1;
 	head=NULL;
 	while(x)
 	{
		newnode=(struct node *)malloc(sizeof(struct node));
 		printf("  Enter Data: ");
 		scanf("%d",&newnode->data);
 		newnode->link=0;
 		if(head==NULL)
 			temp=head=newnode;
	 	else
 		{
 			temp->link=newnode;
 			temp=newnode;
 		}
  		printf("Enter 0 to stop or 1 to continue: ");
  		scanf("%d",&x);
 	}
}

void display()
{
	struct node *t;
	t=head;
	while(t!= NULL)
    {
        printf("%d --> ",t->data);
        t = t->link;
    }
    printf("NULL");
}
void frequency(int el)
{
	int frequency=0;
	temp=head;
	while(temp!=NULL)
	{
		if(temp->data==el)
		{
			frequency++;
		}
		temp=temp->link;
	}
	printf("The frequency of %d is:%d",el,frequency);
}
//void duplicate()
//{
//	f=frequency();
//	if(f!=0)
//		printf("It is a duplicate element");
//}
void sort()
{
	int temp1=0;
	temp=head;
	while(temp->link!=NULL)
	{
		t=temp->link;
		while(t!=NULL)
		{
			if(temp->data>t->data)
			{
				temp1=temp->data;
				temp->data=t->data;
				t->data=temp1;
			}
			t=t->link;
		}
		temp=temp->link;
	}
	
	printf("List sorted\n");
}
void search(int el)
{
	temp=head;
	int flag=0;
	while(temp!=NULL)
	{
		if(temp->data==el)
		{
			flag=1;
			printf("Element found.");
		}
		temp=temp->link;
	}
	if(flag==0)
		printf("Element not found");
}
void reverse()
{
	struct node *nextnode,*prevnode;
	prevnode=NULL;
	temp=nextnode=head;
	while(nextnode!=NULL)
	{
		nextnode=temp->link;
		temp->link=prevnode;
		prevnode=temp;
		temp=nextnode;
	}
	head=prevnode;
}
