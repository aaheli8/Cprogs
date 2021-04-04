/*Write a menu driven C program to insert and delete element at following positions (Start, End,
Before and After a given position) of a singly linked list and also reverse the same.*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start=NULL;
void insert_start();
void insert_before();
void insert_end();
void insert_after();
void delete_start();
void delete_before();
void delete_end();
void delete_after();
void reverse();
void display();
void main()
{
	struct node *temp,*ptr;
	int num,n,i,ch;
	printf("Enter the number of data to be inserted--->");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\nEnter data to be inserted--->");
	    scanf("%d",&num);
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=num;
		if(start==NULL)
		{
			temp->next=NULL;
			start=temp;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
			{
				ptr=ptr->next;
			}
			ptr->next=temp;
			temp->next=NULL;
		}
		
	}
	display();
	printf("\n--------------------------------------------------\n");
	while(1)
	{
	
	
	printf("\nEnter 1 to insert a node at the beginning-->");
	printf("\nEnter 2 to insert a node at the end-->");
	printf("\nEnter 3 to insert a new node before the given position-->");
	printf("\nEnter 4 to insert a new node after the given position-->");
	printf("\nEnter 5 to delete a node at the beginning-->");
	printf("\nEnter 6 to delete a node at the end-->");
	printf("\nEnter 7 to delete a  node before the given position value-->");
	printf("\nEnter 8 to delete a  node after the given position value-->");
	
	printf("\nEnter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		    insert_start();
		    display();
		    break;
		case 2:
			insert_end();
			display();
			break;
		case 3:
			insert_before();
			display();
			break;
		case 4:
			insert_after();
			display();
			break;
		case 5:
			delete_start();
			display();
			break;
		case 6:
			delete_end();
			display();
			break;
		case 7:
			delete_before();
			display();
			break;
		case 8:
			delete_after();
			display();
			break;
			
		    
		default:exit(0);
	}
	
	
}
}
void insert_start()
{
	struct node *temp;
	int val;
	printf("Enter the value to be inserted at the beginning--->");
	scanf("%d",&val);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=start;
	start=temp;
	
}
void insert_end()
{
	struct node*ptr,*temp;
	int val;
	printf("Enter the value to be inserted at the end--->");
	scanf("%d",&val);
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=val;
	temp->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=temp;	
}
void insert_before()
{
	struct node *temp,*ptr,*preptr;
	int val;
	printf("\nEnter value before which data is to be inserted: ");
	scanf("%d",&val);
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number to be inserted-----> ");
	scanf("%d",&temp->data);
	ptr=start;
	preptr=ptr;
	while(ptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	if(preptr==ptr)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		preptr->next=temp;
		temp->next=ptr;
	}
}

void insert_after()
{
	struct node *temp,*ptr,*preptr;
	int val;
	printf("\nEnter value after which data is to be inserted: ");
	scanf("%d",&val);
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the number to be inserted-----> ");
	scanf("%d",&temp->data);
	ptr=start;
	preptr=ptr;
	while(preptr->data!=val)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	if(ptr==preptr)
		ptr=ptr->next;
	preptr->next=temp;
	temp->next=ptr;
	
}
void delete_start()
{
	struct node*ptr;
	ptr=start;
	start=start->next;
	free(ptr);
}
void delete_end()
{
	struct node*ptr,*preptr;
	ptr=start;
	while(ptr->next!= NULL)
	{
		preptr=ptr;
		ptr=ptr->next;
	}
	preptr->next=NULL;
	free(ptr);
}
void delete_before()
{
	struct node *ptr,*preptr,*temp;
	int val;
	printf("Enter the value before which the node has to be deleted-->");
	scanf("%d",&val);
	ptr=start;
	preptr=ptr->next;
	while(preptr->data != val)
	{
		temp=ptr;
		ptr=preptr;
		preptr=preptr->next;
	}
	temp->next=preptr;
	free(ptr);
} 
    
    
void delete_after()
{
	struct node *ptr, *preptr;
    int val;
    printf("\n Enter the value after which the node has to deleted --->");
    scanf("%d", &val);
    ptr=start;
    preptr=ptr;
    while(preptr->data != val)
    {
      preptr=ptr;
      ptr = ptr->next;
    }
    preptr->next=ptr->next;
    free(ptr);
}
void display()
{
	struct node*ptr;
	ptr=start;
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}	
	
	

