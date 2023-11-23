//Insertion sort
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
void sort()
{
	int temp;
	for(i=1;i<n;i++)
	{
		temp=a[i];
		j=i-1;
		while(j>=0 && a[j]>temp)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
void display()
{
	printf("The array is:\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
}
