//insert elements in a singly linked list
#include<stdio.h>
#include<stdlib.h>
void insert_at_beg(int);
void insert_at_anypos(int,int);
void insert_at_end(int);
void insert_after(int,int);
void insert_before(int,int);
void display();


struct node
{
	int data;
	struct node *link;

};
struct node * head=NULL;
struct node * newnode, *temp;
int main()
{
	
	printf("Enter 1 to insert element at the begining:\n");
	printf("Enter 2 to insert element at the end:\n");
	printf("Enter 3 to insert element at the any position:\n");
	printf("Enter 4 to insert element after an element:\n");
	printf("Enter 5 to insert element before an element:\n");
	printf("Enter 6 to display:\n");
	int ch,el,pos,key;
	
	while (1)
    {
        printf("\n  Enter your choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
        	case 1:
				printf("\nINSERTING AT THE BEGINNING");
				printf("\nEnter the element you want to insert: ");
				scanf("%d",&el);
				insert_at_beg(el);
				break;
			case 2:
				printf("\nINSERTING AT THE END");
				printf("\nEnter the element you want to insert: ");
				scanf("%d",&el);
				insert_at_end(el);
				break;
			case 3:
				printf("\nINSERTING AT ANY POSITION");
				printf("\nEnter the element you want to insert: ");
				scanf("%d",&el);
				printf("Enter the position: ");
				scanf("%d",&pos);
				insert_at_anypos(el,pos);
				break;
   			
			case 4:
				printf("\nINSERTING AFTER AN ELEMENT");
				printf("\nInsert the element after which you want to insert new node: ");
				scanf("%d",&key);
				printf("\nEnter the element you want to insert: ");
				scanf("%d",&el);
				insert_after(key,el);
				break;
			case 5:
				printf("\nINSERTING BEFORE AN ELEMENT\n");
				printf("\nInsert the element before which you want to insert new node: ");
				scanf("%d",&key);
				printf("\nEnter the element you want to insert: ");
				scanf("%d",&el);
				insert_before(key,el);
				break;
			case 6:
   				display();
   				break;
			default:
				printf("wrong input!");

		}
	}
}
void insert_at_beg(int el)
{
	struct node *temp;
	temp= (struct node*)malloc(sizeof(struct node));
	temp->data=el;
	temp->link=head;
	head=temp;
}
void insert_at_end(int el)
{
	if(head==NULL)
		insert_at_beg(el);
	else
	{
		struct node *temp;
		temp=(struct node *)malloc(sizeof(struct node));
		temp->data=el;
		temp->link=NULL;
		struct node *t;
		t=head;
		while(t->link!=NULL)
		{
			t=t->link;
		}
		t->link=temp;
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
void insert_at_anypos(int el,int pos)
{
	if(pos<=0)
		printf("Insertion not possible");
	else if(pos==1)
		insert_at_beg(el);
	else
	{
		int i=1;
		struct node *temp,*t;
		temp=(struct node *)malloc(sizeof(struct node));
		t=head;
		temp->data=el;
		while((i<pos-1) && (t !=NULL))
		{
			t=t->link;
			i++;
		}
		if(t==NULL)
			printf("Invalid position.");
		else
		{
			temp->link=t->link;
			t->link=temp;
			
		}
	}
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
			temp=newnode;
			printf("Element Inserted");
		}
		temp=temp->link;
	}
	if(flag==0)
	printf("\n%d is absent in the list",key);
}
	
