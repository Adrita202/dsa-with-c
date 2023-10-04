//add two pollynomial
#include<stdio.h>
#include<stdlib.h>
struct node
{
	float coef;
	int ex;
	struct node *link;
};
struct node *start1,*start2,*start3;
struct node* create_node(struct node *start,float c,int e)
{
	struct node *temp,*new;
	new=(struct node*)malloc(sizeof(struct node));
	new->coef = c;
	new->ex = e;
	new->link=NULL;
	temp = start;
	if(temp==NULL)
	{
		new->link = start;
			start = new;
	}
	else
	{
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		new->link=temp->link;
		temp->link=new;
	}
	return start;
}

struct node* create(struct node *start)
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
		start=
		create_node(start,coeff,expo);
	}
	return start;
}
void polynomialAddition()
{
	struct node *t1,*t2;
	t1=start1;
	t2=start2;
	while(t1!=NULL && t2!=NULL)
	{
		if(t1->ex==t2->ex)
		{
			start3 = create_node(start3,t1->coef+t2->coef,t1->ex);
			t1=t1->link;
			t2=t2->link;
		}
		else if(t1->ex>t2->ex)
		{
			start3 = create_node(start3,t1->coef,t1->ex);
			t1=t1->link;
		}
		else
		{
			start3 = create_node(start3,t2->coef,t2->ex);
			t2=t2->link;
		}
	}
	while(t1!=NULL)
	{
		create_node(start3,t1->coef,t1->ex);
		t1=t1->link;
	}
	while(t2!=NULL)
	{
		create_node(start3,t2->coef,t2->ex);
		t2=t2->link;
	}


}
void display(struct node *start)
{
	if(start==NULL)
		printf("NO polynomial\n");
 	else
 	{
 		struct node *t=start;
		while(t!=NULL)
		{
			printf("%.1fx^%d",t->coef,t->ex);
			t = t->link;
			if(t!=NULL)
				printf("+");
			else
				printf("\n");
		}
	}
}
	
int main()
{
	int ex,ch,i,n=0;
	float coef;
	printf("Enter 1 to create the 1st polynomial\n");
	printf("Enter 2 to create the 2nd polynomial\n");

	printf("Enter 3 for addion of the polynomial\n");
	printf("Enter 4 to display the result\n");
	while(1)
	{
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				start1=create(start1);
				printf("Displaying the polynomial:\n");
				display(start1);
				break;
			case 2:
				start2=create(start2);
				printf("Displaying the polynomial:\n");
				display(start2);
				break;
			case 3:
				polynomialAddition();
				break;
			case 4:
				display(start3);
				break;
			default:
				printf("invalid choice\n");

		}
	}
}
