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
void movezero(int n,int *arr)
{
	int i,j=-1;
	for(i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			j++;									//using pivot idea
			swap((arr+i),(arr+j));
		}
	}
}
int main()
{
	int arr[]={0,0,2,0,3,4,5,6,0};
	int n=sizeof(arr)/sizeof(int);
	movezero(n,arr);
	printarr(n,arr);
	return 0;
}
