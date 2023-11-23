//Binary search tree create, search, delete
#include<stdio.h>
#include<stdlib.h>
#define MAX 50
struct node {
    int data;
    struct node *left;
	struct node *right;
};
struct node *root=NULL;
struct node *node=NULL;
struct node *insert(struct node *tree,int el);
struct node *bst_search(struct node *p,long key);
struct node* bst_search_iterative(struct node *root,long key);
struct node *bfs(struct node *tree);
struct node *minValueNode(struct node *);
struct node *delete(struct node *,int);
struct node* queue[MAX];
int start=-1,end=-1,s,i;
int count = 1;

int main()
{
    int ch,key;
    long el;
    printf("Enter 1 to insert a node in the binary search tree \n");
    printf("Enter 2 to perform bst search\n");
    printf("Enter 3 to perform iterative bst search\n");
    printf("4.Perform BFS:\n");
    printf("5.Delete element:\n");
    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter an element : To quit enter 0 :\n");
                scanf("%ld",&el);
                while(el!=0)
                {
                    root=insert(root,el);
                    scanf("%ld",&el);
                }
                break;
            case 2:
                printf("Enter an element :\n");
                scanf("%ld",&el);
                struct node* n=bst_search(root,el);
                if(n!=NULL)
                    printf("Found:%d\n",n->data);
                else
                    printf("Element not found.\n");
                break;
            case 3:
                printf("Enter an element :\n");
                scanf("%ld",&el);
                struct node* found=bst_search_iterative(root,el);
                if(found!=NULL)
                {
                    printf("Found:%d\n",found->data);
                }
                else
                {
                    printf("Element not found.\n");
                }
                break;
            case 4:
            	printf("BFS:\n");
            	bfs(root);
				break;
			case 5:
            	printf("Enter the element you want to delete:");
            	scanf("%d",&key);
            	delete(node,key);
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


struct node *insert(struct node *tree,int el)
{
    if(tree==NULL)
    {
        tree=(struct node *)malloc(sizeof(struct node));
        tree->data=el;
        tree->left=NULL;
        tree->right=NULL;
    }
    else if(el<tree->data)
    {
        tree->left=insert(tree->left,el);
    }
    else if(el>tree->data)
    {
        tree->right=insert(tree->right,el);
    }
    return tree;
}

struct node *bst_search(struct node *p,long key)
{
    if(p==NULL || p->data==key)
        return p;
   	else if(key<p->data)
        return bst_search(p->left,key);
    else
        return bst_search(p->right,key);
}

struct node* bst_search_iterative(struct node *root,long key)
{
    while(root!=NULL)
    {
        if(key<root->data)
        {
            root=root->left;
        }
        else if(key>root->data)
        {
            root=root->right;
        }
        else
        {
            return root;
        }
    }
    return root;
}
void q_insert(struct node *e)
{
	if(end == MAX-1)
	{
		printf("Overflow \n");

	}
	else{
		if(start==-1)
		{
			start++;
		}
		end++;
		queue[end]=e;

	}
}
void q_delete()
{
	if(start==-1 || start>end)
	{
		printf("\nUnderflow");
	}
	else{
		start++;
	}

	if(start > end)
	{
		start = end = -1;
	}
}
struct node *bfs(struct node *tree)
{
	if(root!=NULL)
	{
		q_insert(root);

	}
	while(q_size()!=0)
	{
		s = q_size();
		for(i=0;i<s;i++)
		{
			node = queue[start];

			if(node->left!=NULL)
			{
				q_insert(node->left);
			}
			if(node->right!=NULL)
			{
				q_insert(node->right);
			}
			printf("%d\t",node->data);
			q_delete();
		}
		printf("\n");
	}
}
int q_size()
{
	return end-start+1;
}
	
//struct node *delete(struct node *node,int key)
//{
//	struct node *temp;
//    if (node==NULL)
//        return node;
//
//    if (key<node->data)
//        node->left=delete(node->left,key);
//
//    else if (key>node->data)
//        node->right = delete(node->right,key);
//    else
//    {
//        if (node->left == NULL)
//        {
//            temp=node->right;
//            free(node);
//            return temp;
//        }
//        else if (node->right == NULL)
//        {
//            temp=node->left;
//            free(node);
//            return temp;
//        }
//
//        temp=minValueNode(node->right);
//        node->data=temp->data;
//        node->right=delete(node->right,temp->data);
//    }
//    return node;
//}
//struct node *minValueNode(struct node *node)
//{
//    struct node *temp = node;
//    while (temp && temp->left!= NULL)
//        temp = temp->left;
//
//    return temp;
//}
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
