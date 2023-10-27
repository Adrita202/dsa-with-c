#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *prev;
	int data;
	struct node * next;
};
struct node *tail=NULL;
struct node *head=NULL;
struct node *temp, *newnode;
int main()
{
	int ch,pos,el;
	printf(" 1 to insert element at first \n");
	printf(" 2 to insert element at any position \n");
	printf(" 3 to insert at last \n");
	printf(" 4 to display doubly linked list \n");
	printf(" 5 to delete the first element\n");
	printf(" 6 to delete the last element\n");
	printf(" 7 to delete the element at any position\n");

	while(1)
	{
		printf("\nEnter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the element : ");
				scanf("%d",&el);
				insert_at_beg(el);
				break;
			case 2:
				printf("Enter the element : ");
				scanf("%d",&el);
				printf("Enter the position : ");
				scanf("%d",&pos);
				insert_at_anypos(el,pos);
				break;
			case 3:
				printf("Enter the element : ");
				scanf("%d",&el);
				insert_at_end(el);
				break;
			case 4:
				display();
				break;
			case 5:
				delete_from_beg();
				break;
			case 6:
			//	delete_at_end();
				break;
			case 7:
				printf("Enter any Position :");
				scanf("%d",&pos);
		//		delete_at_any_pos(pos);
				break;
			default :
				printf("invalid choice");

		}
	}
}



void insert_at_beg(int el)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=el;
	newnode->prev=tail;
	newnode->next=head;
	if(head==NULL)
		head=tail=newnode;
	else
	{
		head->prev=newnode;
		head=newnode;
	}
}
void insert_at_end(int el)
{
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=el;
	newnode->prev=tail;
	newnode->next=head;
	if(head==NULL)
		head=tail=newnode;
	else
	{
		tail->next=newnode;
		head->prev=newnode;
		tail=newnode;
	}
	
}
void insert_at_anypos(int el, int pos)
{
	int i=1,l;
	temp=tail->next;
	
	if(pos<1)
		printf("Invalid position\n");
	else if(pos==1 )
		insert_at_beg(el);
	else
		newnode=(struct node*)malloc(sizeof(struct node));
		newnode->data=el;
		while(i<pos-1 && temp != NULL)
		{
			temp=temp->next;
			i++;
		}
		if(temp==tail)
			printf("Invalid position.");
		else
		{

			newnode->prev=temp;
			newnode->next=temp->next;
			temp->next->prev = newnode;
			temp->next = newnode;
		}
}
void display()
{
	temp= head;
	if(head == NULL)
	{
		printf("list is empty");
	}
	else
	{
		while(temp != tail)
		{
			printf("%d ->",temp->data);
			temp=temp->next;
		}
		printf("%d",temp->data);
	}
}
void delete_from_beg()
{
	temp=tail->next;
	if(tail==NULL)
		printf("The list is empty");
	else if(tail->next=tail)
	{
		tail=NULL;
		free(temp);
	}
	else
	{
		temp=tail->next;
		temp->prev=tail;
		tail->next=temp;
		free(temp);
	}
}
void delete_from_end()
{
	temp = tail;
	if(temp == NULL)
	{
		printf("list is empty");
	}
	else if(tail->next == tail)
	{
		 tail = NULL;
		free(temp);
	}
	else
	{
		tail = tail->prev;
		tail->next = head;
		head->prev = tail;
		free(temp);
	}
}
void delete_from_anypos(int pos)
{
	if(pos==0)
		printf("invalid position");
	else if(pos==1)
		delete_at_begin();
	else
	{
		struct node  *temp,*t,*l;
		temp = (struct node*)malloc(sizeof(struct node));
		int i=1;
		l = start;
		temp=start;
		while(i<pos && l!=NULL)
		{
			temp=temp->next;
			l = l->next;
			i++;
		}
		if(l==NULL)
		{
			printf("Invalid position");
		}
		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			if(temp->next == start)
			{
					tail = temp->prev;
					free(temp);
			}
			else
			{
				free(temp);
			}
		}
	}
}


	
}
