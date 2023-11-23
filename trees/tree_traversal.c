//Binary tree traversal
#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
struct node *insert(struct node *,long);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

struct node *ptr=NULL;
int n, i, num,ch,count=1;
void main()
{
	//ptr = NULL;
	printf("Enter integer: To quit enter 0:");
	scanf("%d",&num);
	while(num!=0)
	{
		ptr=insert(ptr,num);
		scanf("%d",&num);
	}
	while(1)
	{

		printf("1.Inorder traversal\n2.Preorder traversal\n3.Postorder traversal: ");
		printf("\nEnter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("\nINORDER TRAVERSAL  : \n");
    			inorder(ptr);
    			break;
			case 2:
				printf("\nPREORDER TRAVERSAL : \n");
    			preorder(ptr);
    			break;
			case 3:
    			printf("\nPOSTRDER TRAVERSAL : \n");
    			postorder(ptr);
				break;
			default:
				printf("Invalid choice");
		}
	}
	
}
struct node *insert(struct node *ptr,long num)
{
	if(ptr==NULL)
	{
		
		ptr=(struct node *)malloc(sizeof(struct node));
		ptr->left=ptr->right=NULL;
		ptr->data=num;
		count++;
	}
	else
	{
		if(count%2==0)
			ptr->left=insert(ptr->left,num);
		else
			ptr->right=insert(ptr->right,num);
		
	}
	return (ptr);
}
// LEFT RIGHT ROOT
void postorder(struct node *ptr)
{
	if(ptr!=NULL)
		{

	postorder(ptr->left);
	postorder(ptr->right);
	printf("%d\n",ptr->data);
}
}
// ROOT LEFT RIGHT
void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{

		printf("%d\n",ptr->data);
		preorder(ptr->left);
		preorder(ptr->right);
	}
}
// LEFT ROOT RIGHT
void inorder(struct node*ptr)
{
	if(ptr!=NULL)
	{

	inorder(ptr->left);
	printf("%d\n",ptr->data);
	inorder(ptr->right);
	}
}

