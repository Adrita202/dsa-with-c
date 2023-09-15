#include<stdio.h>
#include<stdlib.h>
void delete_element(int);
void delete_from_beg(int);
void display();
void create();
struct node
{
	int data;
	struct node *link;

};
struct node * head=NULL;
struct node *temp,*t,*newnode;
int main()
{
	printf("Enter 1 to create a linked list:\n");
	printf("Enter 2 to delete element:\n");
	printf("Enter 3 to display:\n");
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
				printf("\nEnter the element you want to delete: ");
				scanf("%d",el);
				delete_element(el);
				break;
   			case 3:
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
void delete_from_beg(el)
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
void delete_element(el)
{
	struct node *temp1;
	t=head;
	head=temp->link;
	free(t);
	printf("Element deleted!!!\n");
	if(head!=NULL)
	{
		
	}
	
	
	
	
	
	temp=head;
	if(temp->data ==el)
	{
		delete_from_beg(el);
	}
	else
	{
		temp1 =temp->link;
		while(temp1!= NULL)
		{
			if(temp1->data == el)
			{
				if(temp1->link!= NULL)
				{
					temp->link =temp1->link;
					t=temp1;
					free(t);
					temp1=temp->link;
				}
				else
				{
					temp->link=NULL;
					t=temp1;
					free(t);
				}
			}
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

