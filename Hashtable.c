//To implemet hash tables
#include<stdio.h>
#include<stdlib.h>
#define SIZE 20
#define PRIME 11
int arr_ht[SIZE];
void insert();
void delete_ht();
void display();
void search();
void main()
{
	int ch,i;
	for(i=0;i<SIZE;i++)
	{
		arr_ht[i]=-1;
	}
	printf("\nEnter 1 to INSERT in hash table");
	printf("\nEnter 2 for DELETION of elements");
	printf("\nEnter 3 for DISPLAY");
	printf("\nEnter 4 for SEARCHING");
	printf("\nEnter 5 to Exit");
	while(1)
	{
	    printf("\nEnter the choice------>\n");
		scanf("%d",&ch);
		switch(ch)
		{
		
		case 1:
			insert();
			break;
		case 2:
			delete_ht();
			break;
		case 3:
		    display();
			break;
		case 4:
			search();
			break;
		default:
		   exit(0);
			
	    }
	}
}
void insert()
{
	int val,key;
	printf("\nEnter the element to be inserted---->");
	scanf("%d",&val);
	key=val%PRIME;
	if(arr_ht[key] == -1)
    {   
        arr_ht[key] = val;
        printf("\nValue inserted is %d at position %d", val,key);
    }
    else
    {   
        printf("\nCollision");
        while(arr_ht[key]!=-1 && key<SIZE)key++;
        arr_ht[key] = val;
        if(key==SIZE)
        	printf("\nValue Can't be inserted at this position");
        else
            arr_ht[key] = val;
        	printf("\nValue inserted at  position %d",key);
        
    }
	
}
void delete_ht()
{
    int val,key;
    printf("\nEnter the element to be deleted---->");
	scanf("%d",&val);
	key = val % PRIME;
    while(arr_ht[key]!= val && key<SIZE)
    	key++;
    if(key==SIZE)
    	printf("\nValue was not found");
    else
    {
    	arr_ht[key] = -1;
    	printf("\nValue deleted");
	}     
}
void display()
{
    int i;
    for(i = 0; i < SIZE; i++)
    {
    	if(arr_ht[i]!=-1)
    		printf("arr_ht[%d] => %d\n",i,arr_ht[i]);
	}
    printf("\n");	
}
void search()
{
	int val,key;
	printf("\nEnter the element to be searched---->");
	scanf("%d",&val);
	key = val % PRIME;
    while(arr_ht[key]!= val && key<SIZE)
    	key++;
    if(key==SIZE)
    	printf("Value was not found");
    else
    {
    	printf("\n Value %d is present at position %d",val,key);
	} 
}
