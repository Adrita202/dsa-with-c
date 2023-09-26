#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void display();
struct node
{
	int data;
	struct node *link;

};
struct node * head=NULL;
int main()
{

	printf("1.Insert element to queue \n");
    printf("2.Delete element from queue \n");
    printf("3.Display all elements of queue \n");
    printf("4.Quit \n");
    int choice;
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);
        int el;
        switch (choice)
        {
            case 1:
            	printf("Enter the element to insert: ");
            	scanf("%d",&el);
            	insert(el);
            	break;
            case 2:
            	delete();
            	printf("Element deleted\n");
            	break;
            case 3:
            	display();
            	break;
			case 4:
            	exit(0);
            default:
            printf("Wrong choice \n");
        }
    }
}
void insert(int el)
{
	if(head==NULL)
	{
		struct node *temp;
		temp= (struct node*)malloc(sizeof(struct node));
		temp->data=el;
		temp->link=head;
		head=temp;
	}
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
//void delete_from_beg()
void delete()
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
void display()
{
	struct node *t;
	t=head;
	while(t!= NULL)
    {
        printf("%d ",t->data);
        t = t->link;
    }
    printf("\n");
}
