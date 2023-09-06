#include<stdio.h>
#include<stdlib.h>
void insert_after(int ,int);
void insert_before(int,int);
void display();
void create();
struct node
{
	int data;
	struct node *link;

};
struct node * head=NULL;
struct node *newnode,*temp,*t;


int main()
{
	printf("Enter 1 to create a list:\n");
	printf("Enter 2 to insert element after an element:\n");
	printf("Enter 3 to insert element before an element:\n");
	printf("Enter 4 to display:\n");
	printf("Enter 5 to find the frequency:\n");
	//printf("Enter 6 to sort the list: ");
	printf("Enter 7 to search any element:\n");
	int ch,el,key;
	while (1)
    {
        printf("\n  Enter your choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
        	case 1:
        		printf("Creating a list:\n");
        		create();
        		break;
        	case 2:
				printf("\nINSERTING AFTER AN ELEMENT");
				printf("\nInsert the element after which you want to insert new node: ");
				scanf("%d",&key);
				printf("\nEnter the element you want to insert: ");
				scanf("%d",&el);
				insert_after(key,el);
				break;
			case 3:
				printf("\nINSERTING BEFORE AN ELEMENT\n");
				printf("\nInsert the element before which you want to insert new node: ");
				scanf("%d",&key);
				printf("\nEnter the element you want to insert: ");
				scanf("%d",&el);
				insert_before(key,el);
				break;
			case 4:
				printf("\nDISPLAYING THE LIST:\n");
				display();
				break;
   			default:
   				printf("INVALID CHOICE\n");
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
void insert_after(int key,int el)
{
		int flag;
		newnode=(struct node*)malloc(sizeof(struct node));
		temp=head;
		newnode->data=el;
		while(temp!=NULL)
		{
			if(temp->data == key)
			{
				newnode->link=temp->link;
				temp->link=newnode;
				flag=1;
				printf("Element Inserted");
				}
			temp=temp->link;
		}
		if(flag==0)
			printf("\n%d is absent in the list",key);
}
void insert_before(int key,int el)
{
	int flag;
	newnode=(struct node*)malloc(sizeof(struct node));
	temp=head;

	flag=0;
	newnode->data=el;
	while(temp->link!=NULL)
	{
		if(head->data==key)
		{
			flag=1;
			newnode->link=temp;
			head=newnode;
		}
		else if(temp->link->data==key)
		{
			flag=1;
			newnode->link=temp->link->link;
			temp->link=newnode;
			printf("Element Inserted");
		}
		temp=temp->link;
	}
	if(flag==0)
	printf("\n%d is absent in the list",key);
}

