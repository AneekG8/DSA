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
void sort(int n,int *arr)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(arr[i]>arr[j])
				swap((arr+i),(arr+j));
		}
	}
}
void func(int n,int *arr)
{
	int i,j,temp[n];
	for(i=0;i<n;i++)
	{
		temp[i]=arr[i];
	}
	sort(n,temp);
	if(n%2==0)
	{
		for(i=0,j=n/2-1;i<n;i=i+2,j--)
			arr[i]=temp[j];
		for(i=1,j=n/2;i<n;i=i+2,j++)
			arr[i]=temp[j];
	}
	else
	{
		for(i=0,j=n/2;i<n;i=i+2,j--)
			arr[i]=temp[j];
		for(i=1,j=n/2+1;i<n;i=i+2,j++)
			arr[i]=temp[j];
	}
}
int main()
{
	int arr[]={1, 2, 3, 4, 5, 6, 7,8};
	int n=sizeof(arr)/sizeof(int);
	func(n,arr);
	printarr(n,arr);
	return 0;
}
