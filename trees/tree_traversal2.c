// Tree traversal(college)
#include<stdio.h>
#include<stdlib.h>

typedef struct nodeStructure {
    struct nodeStructure *left;
    struct nodeStructure *right;
    int data;
}node;

void insert(node **, int);       // **p -> pointer to a pointer
void inorder(node *);
void preorder(node *);
void postorder(node *);

node *ptr;
int n, i, num;

void main() {
    ptr = NULL;
    // ptr->data = NULL;

    printf("\nProgram for Tree Traversal\n");
    printf("Enter no. of nodes : ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
	{
        printf("\nVALUE : ");
        scanf("%d",&num);
        insert(&ptr, num);
    }

    printf("\nINORDER TRAVERSAL  : \t");
    inorder(ptr);

    printf("\nPREORDER TRAVERSAL : \t");
    preorder(ptr);

    printf("\nPOSTRDER TRAVERSAL : \t");
    postorder(ptr);
}

void insert(node **p, int n) {
    if((*p) == NULL) {
        printf("\nLeaf node created");
        (*p) = malloc(sizeof(node));
        (*p)->left = NULL;
        (*p)->right = NULL;
        (*p)->data = num;
        return;
    } else {
        if(num == (*p)->data) {
            printf("\nREPEATED NUMEBR\n");
            return;
        }
        if(num < (*p)->data) {
            printf("\nTOWARDS LEFT");
            insert(&((*p)->left), num);
        } else {
            printf("\nTOWARDS RIGHT");
            insert(&((*p)->right), num);
        }
    }
    return;
}

// LEFT ROOT RIGHT
void inorder(node *p) {
    if(p != NULL) {
        inorder(p->left);
        printf("%d   ", p->data);
        inorder(p->right);
    } else
        return;
}

// ROOT LEFT RIGHT
void preorder(node *p) {
    if(p != NULL) {
        printf("%d   ", p->data);
        preorder(p->left);
        preorder(p->right);
    } else
        return;
}

// LEFT RIGHT ROOT
void postorder(node *p) {
    if(p != NULL) {
        postorder(p->left);
        postorder(p->right);
        printf("%d   ", p->data);
    } else
        return;
}
