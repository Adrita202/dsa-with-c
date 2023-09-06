//insert at position
#include<stdio.h>
#include<stdlib.h>
void insert_at_beg(int);
void insert_at_anypos(int,int);
void insert_at_end(int);
void display();
void count();

struct node
{
	int data;
	struct node *link;

};
struct node * head=NULL;
int main()
{
	printf("Enter 1 to insert element at the begining:\n");
	printf("Enter 2 to insert element at the end:\n");
	printf("Enter 3 to insert element at the any position:\n");
	printf("Enter 4 to display:\n");
	printf("Enter 5 to count the number of nodes: ");
	int ch,el,pos;
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
   				display();
   				break;
			case 5:
				count(head);
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
void count()
{
	int count=0;
	if (head==NULL)
		printf("The list is empty.");
	else
	{
		struct node *t = NULL;
		t=head;
		while(t!=NULL)
		{
			count++;
			t=t->link;
		}
	printf("The number of nodes in the list: %d",count);
	}
}
	
