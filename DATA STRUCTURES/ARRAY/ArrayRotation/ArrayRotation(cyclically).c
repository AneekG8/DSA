/*
cyclically rotation of array by one
*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void printarr(int n,int *arr)
{
	int i=0;
	while(i < n)
	{
		printf("%d ",*(arr+i));
		i++;
	}
}
void cycrotate(int n,int *arr)
{
	int i,temp;
	temp=*(arr+n-1);
	for(i=n-1;i>=1;i--)
	{
		*(arr+i)=*(arr+i-1);
	}
	*(arr+0)=temp;
}
int main()
{
	int arr[]={1,2,3,4,5,6};
	int n=sizeof(arr)/sizeof(arr[0]);								//important
	cycrotate(n,arr);
	printarr(n,arr);
	return 0;
}
