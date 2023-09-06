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
struct node *temp,*t;
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
void create()
{
	int i;
	for (i=5;i>0;i--)
	{
    	struct node* temp = (struct node*)malloc(sizeof(struct node));
    	temp->data = i;
    	temp->link = head;
    	head = temp;
	}
}
void delete_element(el)
{
	struct node *temp1;
	if(temp->data ==el)
	{
		head = temp->link;
		t = temp;
		free(t);
		if(head != NULL)
		delete_from_beg(el);
		else
		{
			printf("\n The list is empty");
		head = NULL;
		}
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
				

