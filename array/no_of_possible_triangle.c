#include<stdio.h>
int i,j,k;
int arr[50];
void input(int);
int posssibleTriangle(int[],int );
int main()
{
	
	int n,count;
	
	printf("Enter the number of elements in the array: ");
	scanf("%d",&n);
	input(n);
	count=posssibleTriangle(arr,n);
		printf("Triangle possible %d: ",count);
//	else
//		printf("triangle not possible");
	
	
}
void input( int n)
{
	printf("Enter the elements of the array(unsorted):\n");
	for(i=0;i<n;i++)
	{
		printf("Element %d:",i+1);
		scanf("%d",&arr[i]);
	}
}
int posssibleTriangle(int arr[],int n)
{
	int count =0;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			for(k=j+1;k<n;k++)
			{
				if((arr[i]+arr[j]>arr[k]) && (arr[i]+arr[k]>arr[j]) &&(arr[k]+arr[j]>arr[i]))
					count ++;
//				else
//					return 0;
				
			}
		}
	}
	return count;
	
}



