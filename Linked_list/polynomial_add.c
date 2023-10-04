#include<stdio.h>
struct node
{
	int ex;
	float coeff;
	struct node *link;

};
struct node *new=(struct node*)malloc(sizeof(struct node));

struct node * start1,*start2,*start3;
void insert_at_last(struct node *,int ,float );

void insert_at_last(struct node *s,int e,float c)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
 	temp=s;
	while(temp->link!=NULL)
	{
		temp=temp->link;
	}
	temp->link=new;
	new->link=NULL;
	new->coeff=c;
	new->ex=e;

}
void polyAdd(struct node *start1,struct node *start2)
{
	struct node *t1=start1;
	struct node *t2=start2;
	struct node *t3=NULL;

	while((t1!=NULL) && (t2!=NULL))
	{
		if(t1->ex==t2->ex)
		{
			create_node(start3,t1->ex,t1->c+t2->c);
			t1=t1->link;
			t2=t2->link;
		}
		else if(t1->ex>t2->ex)
		{
			create_node(start3,t1->ex,t1->c);
			t1=t1->link;
		}
		else
		{
			create_node(start3,t2->ex,t2->c);
			t2=t2->link;
		}
	}
	while(t1!=NULL)
	{
		create_node(start3,t1->ex,t1->c);
		t1=t1->link;
	}
	while(t2!=NULL)
	{
		create_node(start3,t2->ex,t2->c);
		t2=t2->link;
	}
	
}
void create(struct node *start)
{
	int n,i;
	float coeff;
	int expo;
	printf("Enter the no of terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the coeff of term %d: ",i+1);
		scanf("%f",&coeff);
		printf("Enter the exponent of term %d: ",i+1);
		scanf("%d",&expo);
		start=insert_at_last(start,coeff,expo);
		
		
	}
	
}
int main()
{
	int ch;
	printf("Enter 1st polynomial eqn: ");
	create(start1);
	printf("Enter 2nd polynomial eqn: ");
	create(start2);
	polyAdd(start1,start2);
	display(start3);
	
}
void display()
{
	struct node *t=start3;
	while(t!=NULL)
	{
		printf("%fx^%d",t->coeff,t->ex);
		t=t->link;
		if(t!=NULL)
			printf("+");
		else
			printf("\n");
	}
}

	

