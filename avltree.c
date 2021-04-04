//WAP in C to implement AVL Tree
#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct node{
	int val,bal;
	struct node*right;
	struct node*left;
};

void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
struct node* insertavl(struct node*,int,int*);

void main()
{
	int ch,data;
	int ht;
	struct node* tree=NULL;
	printf("\nEnter 1 to INSERT ELEMENTS IN AVL");
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
			scanf("%d",&data);
			tree=insertavl(tree,data,&ht);
			preorder(tree);
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
struct node*insertavl(struct node*ptr, int data , int *ht)
{
	struct node *aptr, *bptr;
	if(ptr == NULL)
	{
		
		ptr=(struct node*)malloc(sizeof(struct node));
		ptr->val=data;
		ptr->left=NULL;
		ptr->right=NULL;
		ptr->bal=0;
		*ht= TRUE;
		return (ptr);
	}
	if( data < ptr -> val)
	{
		ptr->left=insertavl(ptr->left,data,ht);
		if(*ht == TRUE)
		{
			switch(ptr->bal)
			{
				case -1:
					ptr->bal=0;
					*ht=FALSE;
					break;
					
				case 0:
					ptr->bal=1;
					break;
				case 1:
					aptr=ptr->left;
					if(aptr->bal==1)
					{
						printf("LL Rotation\n");
						ptr->left = aptr -> right;
						aptr -> right= ptr;
                        ptr -> bal = 0;
                        aptr -> bal=0;
                        ptr = aptr;
					}
					else
					{
						printf("LR Rotation\n");
					    bptr= aptr-> right;
                        aptr-> right= bptr->left;
                        bptr-> left= aptr;
                        ptr-> left= bptr->right;
                        bptr-> right=ptr;
                        if(bptr-> bal== 1 )
                            ptr-> bal= -1;
                        else
                            ptr-> bal= 0;
                        if(bptr-> bal== -1)
                            aptr-> bal= 1;
                        else
                            aptr-> bal= 0;
                        bptr-> bal=0;
                        ptr= bptr;
					}
					*ht= FALSE;
			}
		}
	}
	if(data >ptr->val)
	{
		ptr->right= insertavl(ptr->right,data,ht);
        if(*ht==TRUE)
        {
           switch(ptr->bal)
           {
            case 1: 
                ptr->bal=0;
                *ht=FALSE;
                break;
            case 0:
                ptr->bal=-1;
                break;
            case -1: 
                aptr=ptr->right;
            if(aptr->bal==-1)
            {
              printf("RR Rotation\n");
              ptr->right=aptr->left;
              aptr->left=ptr;
              ptr->bal=0;
              aptr->bal=0;
              ptr = aptr;
            }
            else
            {
             printf("RL Rotation\n");
             bptr = aptr->left;
             aptr -> left = bptr -> right;
             bptr -> right= aptr;
             ptr -> right= bptr->left;
             bptr -> left= ptr;
             if(bptr -> bal== -1)
                ptr -> bal= 1;
             else
                ptr->bal= 0;
             if(bptr->bal==1)
                aptr->bal=-1;
             else
               aptr->bal = 0;
             bptr->bal=0;
             ptr=bptr;
            }
            *ht=FALSE;
        }
   }
}
 return(ptr);
		
}
	
	void inorder(struct node *tree)
{
    if( tree != NULL)
    {
        inorder(tree->left);
        printf(" %d ",tree->val);
        inorder(tree->right);
    }
}
void preorder(struct node *tree)
{
    if( tree != NULL)
    {
        printf(" %d ",tree->val);
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
        printf(" %d ",tree->val);
    }
}

