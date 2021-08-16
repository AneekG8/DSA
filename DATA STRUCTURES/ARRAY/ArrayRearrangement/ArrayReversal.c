#include<stdlib.h>
#include<stdio.h>
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
void revarr(int start,int end,int *arr)					//this method helps to reverse any selected part of an array
{
	while(start<end)
	{
		swap((arr+start),(arr+end));
		start++;
		end--;
	}
}
void revarr1(int start,int end,int *arr)				//same using recursion
{
	if(start>=end)
		return;
	swap((arr+start),(arr+end));
	revarr(start+1,end-1,arr);
}
int main()
{
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(int);
	revarr(0,n-1,arr);
	printarr(n,arr);
	return 0;
}
