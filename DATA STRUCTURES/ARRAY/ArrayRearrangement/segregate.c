#include<stdio.h>
#include<stdlib.h>
void printarr(int n,int *arr)
{
	int i=0;
	while(i < n)
	{
		printf("%d ",*(arr+i));
		i++;
	}
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void segregate(int n,int *arr)
{
	int i,j=-1;
	for(i=0;i<n;i++)
	{
		if(arr[i]%2==0)					//LOMUTO partition
		{
			j++;
			swap(&arr[j],&arr[i]);
		}
		else
			continue;
	}
}
void segregate1(int n,int *arr)			//this function helps to segregate in O(n/2) time because we are only traversing
{										//through the 1/2 of the array for segregation process
	int i,j,k=0,l=n-1,temp[n];
	for(i=0;i<n;i++)
	{
		temp[i]=arr[i];
	}
	for(i=0,j=n-1;i<j;i++,j--)
	{
		if(temp[i]%2==0)
		{
			arr[k]=temp[i];
			k++;
		}
		else
		{
			arr[l]=temp[i];
			l--;
		}
		if(temp[j]%2==0)
		{
			arr[k]=temp[j];
			k++;
		}
		else
		{
			arr[l]=temp[j];
			l--;
		}
		if(n%2==1)
		{
			arr[k]=temp[k];
		}
	}
}
int main()
{
	int arr[]={1,2,3,4,5,6};
	int n=sizeof(arr)/sizeof(int);
	segregate1(n,arr);
	printarr(n,arr);
	return 0;
}
