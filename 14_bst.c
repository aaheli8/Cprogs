//To form a Binary Search Tree and traverse it in-order, post-order and pre-order using recursion
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*right;
	struct node*left;
};
struct node*tree=NULL;
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node*insertbst(struct node*,int);

void main()
{
	int ch,val;
	printf("\nEnter 1 to INSERT ELEMENTS IN BST");
	printf("\nEnter 2 for INORDER Traversal");
	printf("\nEnter 3 for PREORDER Traversal");
	printf("\nEnter 4 for POSTORDER Traversal");
	printf("\nEnter 5 to Exit");
	while(1)
	{
	    printf("\nEnter the choice------>\n");
		scanf("%d",&ch);
		switch(ch)
		{
		
		case 1:
			printf("Enter data elements--->");
			scanf("%d",&val);
			tree=insertbst(tree,val);
			break;
		case 2:
			printf("\n INORDER Traversal--->\n");
			inorder(tree);
			break;
		case 3:
		    printf("\n PREORDER Traversal--->\n");
			preorder(tree);
			break;
		case 4:
		    printf("\n POSTORDER Traversal--->\n");
			postorder(tree);
			break;
		default:
		   exit(0);
			
	    }
		}
}
struct node *insertbst(struct node *tree, int val)
{
    if(tree == NULL)
    {
        tree = (struct node *)malloc(sizeof(struct node));
        tree->left = tree->right = NULL;
        tree->data = val;
        return tree;
    }
    else
    {
        if(val < tree->data )
            tree->left = insertbst(tree->left,val);
        else 
            tree->right = insertbst(tree->right,val);
        return(tree);
    }
}
void inorder(struct node *tree)
{
    if( tree != NULL)
    {
        inorder(tree->left);
        printf(" %d ",tree->data);
        inorder(tree->right);
    }
}
void preorder(struct node *tree)
{
    if( tree != NULL)
    {
        printf(" %d ",tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}
void postorder(struct node *tree)
{
    if( tree != NULL)
    {
        postorder(tree->left);
        postorder(tree->right);
        printf(" %d ",tree->data);
    }
}
