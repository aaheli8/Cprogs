//Insertion sort using dynamic memory allocation
#include<stdio.h>
#include<stdlib.h>
int  main()
{
   int array[100],n, i,j,temp;;
   int *ptr;
   printf("Enter the number of array elements--->");
   scanf("%d",&n);
   
  ptr = (int*)calloc(n,sizeof(int));
   printf("\nEnter array elements--->");
   for(i=0;i<n;i++) 
   {
   	    scanf("%d",ptr+i);
      
    }
 
	
	for(i=1;i<n;i++)
	{
		temp=*(ptr+i);
		j=i-1;
		while((temp<*(ptr + j))&& (j>=0))
		{
			*(ptr+(j+1))=*(ptr + j);
			j--;
		}
		*(ptr + (j+1))=temp;
	}
	printf("\nThe array in sorted order----->");
    for (i = 0; i < n; i++) 
		printf("%d ", *(ptr + i)); 
	free(ptr);
}



   
   
