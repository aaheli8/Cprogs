//Stack operations (PUSH, POP and DISPLAY) using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
struct node *top=NULL;
void push();
void pop();
void display();
void main()
{
	int ch;
	printf("Choices");
	while(1)
	{
	
	
	printf("\nEnter 1 to perform PUSH-->");
	printf("\nEnter 2 to perform POP-->");
	printf("\nEnter 3 to DISPLAY Stack-->");
	printf("\nEnter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		    push();
		    display();
		    break;
		case 2:
			pop();
			display();
			break;
	  	case 3:
			display();
			break;
			
		default:exit(0);
   }
}
}
void push()
{
	struct node*ptr;
	int val;
	printf("Enter the value to be inserted--->");
	scanf("%d",&val);
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr->data=val;
	if(top == NULL)
	{
		ptr->next=NULL;
		top=ptr;
		
	}
	else
	{
		ptr->next=top;
		top=ptr;
	}
	
}
void pop()
{
	struct node *ptr;
	ptr=top;
	if(top==NULL)
	{
		printf("UNDERFLOW");
	}
	else
	{
		
		top=top->next;
		free(ptr);
	}
	
}
void display()
{
	struct node*ptr;
	
	if(top == NULL)
	{
		printf("\nEMPTY");
		
	}
	else
	{
		ptr=top;
		while(ptr!=NULL)
	    {
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	    }
	}
}


