//Implement circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *tail=NULL;
struct node *newnode,*temp,*t;
void create();
void display();
void insert_at_beg(int);
void insert_at_end(int);
void insert_at_anypos(int,int);
void del_beg();
void del_end();
void delete_from_anypos(int);
void main()
{
	int ch,pos,el,choice;
	printf("1.create a circular linked list:\n");
	printf("2.Display the list:\n");
	printf("3.Insert a node\n");
	printf("4.Delete node from begining:\n");
	printf("5.Delete from end\n");
	printf("6.Delete from any position\n");
	while(1)
	{
		printf("\n\tEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Creating a circular linked list:\n");
				create();
				break;
			case 2:
				printf("Display the list:\n");
				display();
				break;
		case 3:
			printf("Enter the element:");
			scanf("%d",&el);
			printf("Where do you want to insert:\n");
			printf("1.At beg\n 2.At end\n 3.At any position:\n");
			printf("Enter choice(1/2/3): ");
			scanf("%d",&choice);
			switch(choice)
			{
				case 1:
					printf("Inserting node at begining:\n");
					insert_at_beg(el);
					break;
				case 2:
					printf("Inserting node at end:\n");
					insert_at_end(el);
					break;
				case 3:
					printf("Enter the position to insert: ");
					scanf("%d",&pos);
					insert_at_anypos( el,pos);
					break;
				default:
					printf("WRONG CHOICE\n");
			}
		break;
		case 4:
			printf("Deleting node from beg:\n");
			del_beg();
			break;
		case 5:
			printf("Delete node from end");
			del_end();
			break;
		case 6:
			printf("\nDELETING FROM ANY POSITION");
				printf("\nEnter the position: ");
				scanf("%d",&pos);
				delete_from_anypos(pos);
				break;
		default:
			printf("WRONG INPUT");
	}
}
}
void create()
{
	int x=1,el,ch;
	tail=NULL;
	while(x)
	{
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data: ");
		scanf("%d",&el);
		newnode->data=el;
		newnode->link=NULL;
		if(tail==NULL)
		{
			tail=newnode;
			tail->link=newnode;
		}
		else
		{
			newnode->link=tail->link;
			tail->link=newnode;
			tail=newnode;
		}
		printf("Enter 0 to stop or 1 to continue:");
  		scanf("%d",&x);
	}
}
void display()
{
	if(tail==NULL)
		printf("The list is empty");
	else
	{
		temp=tail->link;
		do
		{
			printf("%d->",temp->data);
			temp=temp->link;
		}
		while(temp!=tail->link);
	}
}
void insert_at_beg(int el)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=el;
	if(tail==NULL)
	{
		newnode->link=newnode;
		tail=newnode;
	}
	else
	{
		newnode->link=tail->link;
		tail->link = newnode;
	}

}

void insert_at_end(int el)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=el;
	if(tail==NULL)
	{
		newnode->link=newnode;
		tail=newnode;
	}
	else
	{
		newnode->link=tail->link;
		tail->link=newnode;
		tail=newnode;
	}
}
void del_beg()
{
	temp=tail->link;
	if(tail==NULL)
		printf("The list is empty\n");
	else if(temp==tail)
	{
		tail=0;
		free(temp);
	}
	else
		tail->link=temp->link;
		free(temp);
}
void del_end()
{
	temp=tail->link;
	if(tail==NULL)
		printf("The list is empty\n");
	while(temp->link!=tail)
		temp=temp->link;
	temp->link=tail->link;
	tail=temp;
		
}
void delete_from_anypos(int pos)
{
	if(pos==0)
		printf("deletion not possible");
	else if(pos==1)
		del_beg();
	else
	{
		int i=1;
		temp=tail->link;
		while(i<pos-1 && temp != NULL)
		{
			temp=temp->link;
			i++;
		}
		if(temp==tail)
			printf("Invalid position.");
		else
		{
			t=temp->link;
			temp->link=t->link;
			free(t);
		}
	}
}
void insert_at_anypos(int el,int pos)
{
	if(pos<=0)
		printf("Insertion not possible");
	else if(pos==1)
		insert_at_beg(el);
	else
	{
		int i = 1;
		newnode = (struct node*)malloc(sizeof(struct node));
		newnode->data = el;
		temp = tail->link;
		while(i<pos-1 && temp!=tail)
		{
			temp = temp->link;
			i++;
		}
		if(temp ==tail)
		{
			printf("Invalid Position !\n");
			return;
		}
		newnode->link = temp->link;
		temp->link = newnode;
	}
}

