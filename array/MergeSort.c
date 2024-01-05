//merge sort
#include <stdio.h>

void merge_sort(int arr[], int s, int e);
void merge(int arr[], int s, int mid, int e);

int main()
{
    int arr[10],n,i;
   	printf("Enter number of elements in the array: ");
    scanf("%d",&n);
    printf("\nEnter Elements of the sorted array: \n");
    for (i=0;i<n;i++)
        scanf("%d", &arr[i]);

    merge_sort(arr,0,n-1);
    printf("THe sorted array is: ");
    for (i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
void merge_sort(int arr[],int s,int e)
{
    int mid;
    if (e<=s)
		return;
    mid = (s + e) / 2;
    merge_sort(arr, s, mid);
	merge_sort(arr, mid + 1, e);
    merge(arr,s, mid, e);
}

void merge(int arr[], int s, int mid, int e)
{
    int temp[e-s+1];
    int i=s,j=mid+1,k=0;
    while (i<=mid&&j<=e)
    {
        if (arr[i]==arr[j])
        {
            temp[k++] = arr[i];
            i++;
        temp[k++] = arr[j];
        j++;
        }
		else if(arr[i]<arr[j])
		{
			temp[k++]=arr[i];
			i++;
		}
		else if(arr[j]<arr[i])
		{
			temp[k++]=arr[j];
			j++;
		}
    }
    while (i<=mid)
    {
        temp[k++]=arr[i];
        i++;
    }
    while (j<=e)
    {
        temp[k++]=arr[j++];
    }
    i = 0;
    j = s;

    while(i<k)
    {
        arr[j++] = temp[i++];
    }
}

