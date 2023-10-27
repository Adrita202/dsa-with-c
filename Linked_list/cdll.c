#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
void insert_at_begin(int );
void insert_at_end(int );
void insert_at_any(int ,int);
void display();
void delete_at_begin();
void delete_at_any_pos(int );
void delete_at_end();
struct node *start = NULL;
struct node *start2 = NULL;
struct node *tail = NULL;
int main()
{
	int a,pos,el;
	printf("enter 1 to insert element at first \n");
	printf("enter 2 to insert element at any position \n");
	printf("enter 3 to insert at last \n");
	printf("enter 4 to display doubly linked list \n");
	printf("enter 5 to delete the first element\n");
	printf("enter 6 to delete the last element\n");
	printf("enter 7 to delete the element at any position\n");

	while(1)
	{
		printf("\nchoose a number : ");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
				printf("Enter the element : ");
				scanf("%d",&el);
				insert_at_begin(el);
				break;
			case 2:
				printf("Enter the element : ");
				scanf("%d",&el);
				printf("Enter the position : ");
				scanf("%d",&pos);
				insert_at_any(el,pos);
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
				delete_at_begin();
				break;
			case 6:
				delete_at_end();
				break;
			case 7:
				printf("Enter any Position :");
				scanf("%d",&pos);
				delete_at_any_pos(pos);
				break;
			default :
				printf("invalid choice");

		}
	}
}
void insert_at_begin(int el)
{
	struct node *new;
	new = (struct node*)malloc(sizeof(struct node));
	new->data = el;
	if(start == NULL)
	{
		start = tail = new;
		new->next = start;
		new->prev = tail;
	}
	else
	{
		new->prev = tail;
		new->next = start;
		start->prev = new;
		tail->next = new;
		start = new;
	}

}
void insert_at_end(int el)
{
	struct node *new;
	start = tail->next;
	new = (struct node*)malloc(sizeof(struct node));
	new->data = el;

	if(start == NULL)
	{
		start = tail = new;
		new->next = start;
		new->prev = tail;
	}
	else
	{
		new->prev = tail;
		tail->next = new;
		new->next = start;
		start->prev = new;
		tail = new;
	}
}
void insert_at_any(int el , int pos)
{
	if(pos<=0)
		printf("Not possible\n");
	else if(pos==1)
		insert_at_begin(el);
	else
	{
		int i = 1;
		struct node *new,*temp,*t;
		temp = start;
		t = start;
		new = (struct node*)malloc(sizeof(struct node));
		new->data = el;
		while(i < pos-1 && t != NULL)
		{
			temp = temp->next;
			t = t->next;
			i++;
		}
		if(t == NULL)
		{
			printf("invalid position");
		}
		else
		{
			new->prev = temp;
			new->next = temp->next;
			temp->next->prev = new;
			temp->next = new;
		}
	}
}
void display()
{
	struct node *temp;
	temp = start;
	if(start == NULL)
	{
		printf("list is empty");
	}
	else
	{
		while(temp != tail)
		{
			printf("%d ->",temp->data);
			temp = temp->next;
		}
		printf("%d",temp->data);
	}
}
void delete_at_begin()
{
	struct node *temp;
	temp = start;
	if(temp == NULL)
	{
		printf("list is empty");
	}
	else if(start->next == start)
	{
		start = tail = NULL;
		free(temp);
	}
	else
	{
		start = start->next;
		start->prev = tail;
		tail->next = start;
		free(temp);
	}
}
void delete_at_end()
{
	struct node *temp;
	temp = tail;
	if(temp == NULL)
	{
		printf("list is empty");
	}
	else if(start->next == start)
	{
		start = tail = NULL;
		free(temp);
	}
	else
	{
		tail = tail->prev;
		tail->next = start;
		start->prev = tail;
		free(temp);
	}
}
void delete_at_any_pos(int pos)
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
