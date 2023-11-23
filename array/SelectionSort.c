//selection sort
#include<stdio.h>
void input();
void sort();
void display();
int a[50],i,j,n=0;
void main()
{
	printf("Enter the number of elements:");
	scanf("%d",&n);
	input();
	display();
	sort();
	printf("\nAfter insertion sort:\n");
	display();
}
void input()
{
	printf("Enter the elements of the array:\n");
	for(i=0;i<n;i++)
	{
		printf("element[%d]: ",i);
		scanf("%d",&a[i]);
	}
}
void display()
{
	printf("\nThe array is:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
void sort()
{
	int temp,min;
	for(i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		
		if(min!=i)
		{
			temp=a[i];
			a[i]=a[min];
			a[min]=temp;
		}
	}
}
