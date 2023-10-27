#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;

};
struct node *start=NULL;

void create(int el)
{
	struct node *new, *temp;
	new = (struct node*)malloc(sizeof(struct node));
	new->data = el;
	
	if(start==NULL)
	{
		new->link = NULL;
		start = new;
	}
	else if(start->link == NULL)
	{
		if(el>start->data)
		{
			new->link = start;
			start = new;
		}
		else
		{
			start->link = new;
			new->link = NULL;
		}
	}
	else
	{
		if(el > start->data)
		{
			new->link = start;
			start =  new;
		}
		else
		{
			temp = start;
			while(temp->link != NULL && temp->link->data >= el)
			{
				temp = temp->link;
			}
			new->link = temp->link;
			temp->link = new;
		}
		
	}
}

void display()
{
	struct node *i;
	i=start;
	while(i!= NULL)
    {
        printf("%d --> ",i->data);
        i = i->link;
    }
    printf("NULL");
}

int main()
{
	int ch,el;
	while(1)
	{
		printf("1.Create a list:\n");
		printf("3.Display the list:\n");
		printf("4.exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the data of the node:\n");
				scanf("%d",&el);
				create(el);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}
}

