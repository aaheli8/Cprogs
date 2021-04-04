//Implementation of Queue
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node *front=NULL;
struct node *rear=NULL;
void q_insert();
void q_delete();
void display();
void main()
{
	int ch;
	printf("Choices");
	while(1)
	{
	
	
	printf("\nEnter 1 to INSERT-->");
	printf("\nEnter 2 to DELETE-->");
	printf("\nEnter 3 to DISPLAY Queue-->");
	printf("\nEnter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		    q_insert();
		    display();
		    break;
		case 2:
			q_delete();
			display();
			break;
	  	case 3:
			display();
			break;
			
		default:exit(0);
   }
}
}
void q_insert()
{
	struct node*ptr;
	int val;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter the value to be inserted--->");
	scanf("%d",&val);
	ptr->data=val;
	ptr->next=NULL;
	if(front == NULL)
	{
		front=rear=ptr;
	}
	else
	{
		rear->next=ptr;
		rear=ptr;
	}
}
void q_delete()
{
	struct node *ptr;
	if(front == NULL)
	{
		printf("UNDERFLOW");
	}
	else
	{
		ptr=front;
		front=front->next;
		free(ptr);
	}
	
}
void display()
{
	struct node*ptr;
	
	if(front == NULL)
	{
		printf("\nEMPTY");
		
	}
	else
	{
		ptr=front;
		while(ptr!=NULL)
	    {
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	    }
	}
}


