#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
	
};
void create();
void sort();
void display();
struct node * start=NULL;
struct node * start2=NULL;
struct node * temp1,*temp2,*new;
int main()
{
	int ch;
	while(1)
	{
		printf("1.Create a list:\n");
		printf("2.Sort the list:\n");
		printf("3.Display the list:\n");
		printf("4.exit");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Create a list:\n");
				create();
				break;
			case 2:
				printf("sort the list:\n");
				sort();
				break;
			case 3:
				display();
				break;
			case 4:
				exit(0);
		}
	}
}
//void create()
//{
//	int x=1;
// 	start=NULL;
// 	while(x)
// 	{
//		new=(struct node *)malloc(sizeof(struct node));
// 		printf("\nEnter Data: ");
// 		scanf("%d",&new->data);
// 		new->link=NULL;
// 		if(start==NULL)
// 			temp1=start=new;
//	 	else
// 		{
// 			temp1->link=new;
// 			temp1=new;
// 		}
//  		printf("Enter 0 to stop or 1 to continue\n");
//  		scanf("%d",&x);
// }
//}
void sort()
{
	new =(struct node *)malloc(sizeof(struct node));
	if(start!=NULL)
	{
			
			start2=new;
			new->data=start->data;
			new->link=NULL;
	}
	temp1=start->link;
	while(temp1!=NULL)
	{
		temp2=start2;
		if(temp2->link==NULL)
		{
			if(temp1->data<temp2->data)
			{
				new->data=temp1->data;
				new->link=start2;
				start2=new;
			}
			else
			{
				new->data=temp1->data;
				new->link=NULL;
				temp2->link=new;
					
			}
		}
		else if(temp1->data<start2->data)
		{
			new->data=temp1->data;
			new->link=start2;
			start2=new;
		}
		else
		{
			while(temp2->link!=NULL && (temp1->data > temp2->link->data))
			{
				temp2=temp2->link;
			}
			new->data=temp1->data;
			new->link=temp2->link;
			temp2->link=new;
			
		}
	}
	temp1=temp1->link;
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

