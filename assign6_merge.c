//Merge sort
#include<stdio.h>
void mer_sort(int a[],int,int);
void merge(int a[],int ,int ,int );
void main()
{
	int n, i, a[50];
    printf("Enter the size of the array---->");
	scanf("%d",&n);
	printf("\nEnter the array elements--->");
	for(i=0;i<n;i++)
	{
		printf("\n a[%d]= ",i);
		scanf("%d",&a[i]);
	}
	mer_sort(a,0,n-1);
	printf("\nThe sorted array is----->");
	for(i=0;i<n;i++)
	{
		printf("%d\n", a[i]);
	}
} 

void mer_sort(int a[],int beg,int end)
{
	int mid;
	if(beg<end)
	{
		mid=(beg+end)/2;
		mer_sort(a,beg,end);
		mer_sort(a,mid+1,end);
		merge(a,beg,mid,end);
	}
}
void merge(int a[],int mid,int beg,int end)
{
	int i,j,index,temp[50],k;
	i=beg;
	j=mid+1;
	index=beg;
	while(i<=mid && j<=end)
	{
		if(a[i]<a[j])
		{
		   temp[index]=a[i];
		   i=i+1;	
		}
		else
		{
			temp[index]=a[j];
			j=j+1;
		}
		index=index+1;
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=a[j];
			index=index+1;
			j=j+1;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index]=a[i];
			index=index+1;
			i=i+1;
		}
	}
	for(k=beg;k<index;k++)
	{
		a[k]=temp[k];
	}
}
