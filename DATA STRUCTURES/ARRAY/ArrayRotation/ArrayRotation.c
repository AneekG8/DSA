/*
Author: Aneek
language: C
Time Complexity: O(n*d)
Auxiliary space: O(1)
*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void leftrotateone(int arr[],int d,int n)
{
	int temp=arr[0],i;
	for(i=0;i<n-1;i++)
	{
		arr[i]=arr[i+1];
	}
	arr[n-1]=temp;
}
void leftrotate(int arr[],int d,int n)
{
	int i;
	for(i=0;i<d;i++)
	{
		leftrotateone(arr,d,n);
	}
}
int main()
{
	int n,d,i;
	printf("enter no. of elements:\n");
	scanf("%d",&n);
	printf("enter no. of rotations:\n");
	scanf("%d",&d);
	int arr[n];
	printf("enter the numbers:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	leftrotate(arr,d,n);
	for(i=0;i<n;i++)
	{
		printf("%d",arr[i]);
	}
	return 0;
}
