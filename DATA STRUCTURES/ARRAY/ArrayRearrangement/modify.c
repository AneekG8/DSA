/*
Given an array of integers of size n. Assume ‘0’ as invalid number and all other as valid number.
Convert the array in such a way that if next number is a valid number and same as current number, double its value and replace the next number with 0.
After the modification, rearrange the array such that all 0’s are shifted to the end.
*/
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
	int i,j=n;
	for(i=n-1;i>=0;i--)
	{
		if(arr[i]==0)
		{
			j--;									//using pivot idea
			swap((arr+i),(arr+j));
		}
	}
}
void func(int n,int *arr)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(arr[i]!=0 && arr[i+1]==arr[i])
		{
			arr[i]=arr[i]*2;
			arr[i+1]=0;
		}
		else
			continue;
	}
	movezero(n,arr);
}
int main()
{
	int arr[] = { 0, 2, 2, 2, 0, 6, 6, 0, 0, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
	func(n,arr);
	printarr(n,arr);
	return 0;
}
