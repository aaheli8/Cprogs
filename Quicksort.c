//Quick sort
#include<stdio.h>
int set_loc(int a[],int,int);
void quick_sort(int a[],int ,int);
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
	quick_sort(a,0,n-1);
	printf("\nThe sorted array is----->");
	for(i=0;i<n;i++)
	{
		printf("%d\n", a[i]);
	}
} 
int set_loc(int a[],int beg,int end)
{
	int left,right,loc,flag=0,temp;
	left=beg;
	right=end;
	loc=beg;
	while(flag!=1)
	{
		while((a[loc]<=a[right]) && (loc!=right))
		right=right-1;
		if(loc==right)
		{
			flag=1;
		}
		else if(a[loc]>a[right])
		{
			temp=a[loc];
			a[loc]=a[right];
			a[right]=temp;
			loc=right;
		}
		if(flag!=1)
		{
			while((a[loc]>=a[left]) && (loc!=left))
			  left=left+1;
			if(loc==left)
			{
				flag=1;
			}
			else if(a[loc]<a[left])
			{
				temp=a[loc];
				a[loc]=a[left];
				a[left]=temp;
				loc=left;
			}
		}
	}
	return loc;
}
void quick_sort(int a[],int beg,int end)
{
	int loc;
	if(beg<end)
	{
		loc=set_loc(a,beg,end);
		quick_sort(a,beg,loc-1);
		quick_sort(a,loc+1,end);
	}
}
