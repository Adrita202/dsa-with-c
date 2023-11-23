//Binary Search Tree create,delete
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
struct node *insert(struct node *tree,int el);
void preorder(struct node *tree);
struct node *bst_search(struct node *p,int key);
struct node *delete_c(struct node *p,int el);
struct node *deletee(struct node *p,int el);
int main()
{
	int ch,el,pos;
	printf("Enter 1 to insert a node in the binary search tree \n");
	printf("Enter 2 to perform bst search\n");
	printf("Enter 3 to delete any element\n");
	printf("Enter 4 to display tree in preorder\n");
	while(1)
	{
		printf("Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter an element : To quit enter 0 :\n");
				scanf("%d",&el);
				while(el!=0)
				{
					root=insert(root,el);
					scanf("%d",&el);
				}
				break;
			case 2:
				printf("Enter an element :\n");
				scanf("%d",&el);
				struct node *n=bst_search(root,el);
				if(n!=NULL)
				{
					printf("Found:%d\n",n->data);
				}
				else
				{
					printf("Element not found.\n");
				}
				break;
			case 3:
				printf("Enter the element you want to delete : ");
				scanf("%d",&el);
				root = deletee(root,el);
				break;
			case 4:
				printf("Preorder traversing TREE\n");
				preorder(root);
				break;
			default:
				printf("Invalid Choice\n");
		}
	}
}
struct node *createNode(int data)
{
    struct node* new=(struct node*)malloc(sizeof(struct node));
    new->data=data;
    new->left=new->right=NULL;
    return new;
}

struct node *insert(struct node *root,int data)
{
    if (root==NULL)
	{
        return createNode(data);
    }
    if(data<root->data)
	{
        root->left=insert(root->left,data);
    }
	else if(data>root->data)
	{
        root->right=insert(root->right,data);
    }
    return root;
}

struct node *bst_search(struct node *root,int key)
{
		if(root==NULL || root->data==key)
		{
			return root;
		}
		else if(key < root->data)
		{
			bst_search(root->left,key);
		}
		else
		{
			bst_search(root->right,key);
		}

}
//struct node *delete_c(struct node *root,int el)
//{
//	struct node *temp;
//	if(root->right != NULL)
//	{
//		temp = root->right;
//		while(temp->left != NULL)
//		{
//			temp = temp->left;
//		}
//		temp->left = root->left;
//	}
//	return root->right;
//}
//struct node *deletee(struct node *root,int el)
//{
//	if(root->data == el)
//	{
//		root = delete_c(root,el);
//	}
//	else if (root->right != NULL && root->right->data == el)
//	{
//		root->right = delete_c(root->right,el);
//	}
//	else if(root->left->data == el)
//		root->left = delete_c(root->left,el);
//	else if(root->data > el)
//		deletee(root->left,el);
//	else
//		deletee(root->right,el);

//	return root;
//}
/
struct node *deletee(struct node *node,int key)
{
	struct node *temp,*temp2, *temp3;
	if(node==NULL)
		return node;
	if(node->data==key)
	{
        if (node->left==NULL && node->right==NULL)
        {
            free(node);
            return NULL;
        }
		if (node->left == NULL)
        {
            temp=node->right;
            free(node);
            return temp;
        }
        if (node->right == NULL)
        {
            temp =node->left;
            free(root);
            return temp;
        }

        temp=temp2=node->left;
        temp3=node;
       	//free(node);
        while(temp2->right!=NULL)
        {
        	temp2=temp2->right;
		}
		temp2->right=temp3->right;
		free(temp3);
		return temp;

	}
	else if (node->data>key)
        node->left=deletee(node->left,key);
    else
        node->right=deletee(node->right,key);
}
void preorder(struct node *tree)
{
	if(tree!=NULL)
	{
		printf("%d\n",tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}
