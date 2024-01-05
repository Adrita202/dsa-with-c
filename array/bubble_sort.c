#include<stdio.h>
void bubble_sort(int[],int n);
int main()
{
	int i,j,n,arr[50];
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements in the array:\n");
	for(i=0;i<n;i++)
	{
		printf("Element %d:  ",i);
		scanf("%d",&arr[i]);
	}
	bubble_sort(arr,n);
	printf("Sorted array: ");
	for(i=0;i<n;i++)
	{
		printf("%d  ",arr[i]);
	}
}

void bubble_sort(int a[],int n)
{
	int i,j,temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
}
