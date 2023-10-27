#include<stdio.h>
#include<stdlib.h>
void delete_from_beg();
void delete_from_anypos();
void delete_from_end();
void delete_any_element();
void display();
void create();

struct node
{
	int data;
	struct node *link;

};
struct node * head=NULL;
struct node * temp,*newnode;
int main()
{
	printf("Enter 1 to create a linked list:\n");
	printf("Enter 2 to delete element from the begining:\n");
	printf("Enter 3 to delete element from the end:\n");
	printf("Enter 4 to delete element from the any position:\n");
	printf("Enter 5 to delete any element:\n");
	printf("Enter 6 to display:\n");
	int ch,el,pos;
	while (1)
    {
        printf("\n  Enter your choice : ");
        scanf("%d", &ch);
        switch(ch)
        {
        	case 1:
				printf("CREATING LIST");
				create();
				break;
        	case 2:
				printf("\nDELETING FROM THE BEGINNING");
				delete_from_beg(el);
				break;
			case 3:
				printf("\nDELETING FROM THE END");
				delete_from_end(el);
				break;
			case 4:
				printf("\nDELETING FROM ANY POSITION");
				printf("\nEnter the position: ");
				scanf("%d",&pos);
				delete_from_anypos(pos);
				break;
			case 5:
				printf("\nEnter the element you want to delete: ");
				scanf("%d",el);
				delete_any_element(el);
				break;
   			case 6:
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
 		printf("\nEnter Data: ");
 		scanf("%d",&newnode->data);
 		newnode->link=NULL;
 		if(head==NULL)
 			temp=head=newnode;
	 	else
 		{
 			temp->link=newnode;
 			temp=newnode;
 		}
  		printf("Enter 0 to stop or 1 to continue\n");
  		scanf("%d",&x);
 }
}
void delete_from_beg()
{
	struct node *temp;
	//temp= (struct node*)malloc(sizeof(struct node));
	temp=head;
	if(head==NULL)
		printf("LIst is empty");
	else
	{
		head=head->link;
		free(temp);
	}
}
void delete_from_end()
{
	struct node *t, *temp;
//	temp= (struct node*)malloc(sizeof(struct node));
	t=head;
	if(head->link==NULL)
	{
		t=head;
		head=NULL;
		free(t);
	}
	else
	{
		while(t->link->link!=NULL)
		{
			t=t->link;
		}
			temp=t->link;
			t->link=NULL;
			free(temp);
	}
}
void delete_from_anypos(int pos)
{
	if(pos==0)
		printf("deletion not possible");
	else if(pos==1)
		delete_from_beg();
	else
	{
		struct node  *temp,*t;
//		temp= (struct node*)malloc(sizeof(struct node));
		int i=1;
		temp=head;
		while(i<pos-1 && temp != NULL)
		{
			temp=temp->link;
			i++;
		}
		if(temp==NULL)
			printf("Invalid position.");
		else
		{
			t=temp->link;
			temp->link=t->link;
			free(t);
		}
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
void delete_any_element(el)
{
	struct node *t;
	temp=head;
	if(head->data ==el)
		delete_from_beg(el);
	else
	{
		while(temp->link!= NULL)
		{
			if(temp->link->data == el)
			{
					break;
				}
		}
		t=temp->link;
		temp->link =temp->link->link;
		free(t);
	}
}


