/*
1) Iterate through elements in array
2) If arr[i] >= 0 && arr[i] != i, put arr[i] at i ( swap arr[i] with arr[arr[i]])
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
void rearr(int n,int *arr)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]!=-1 && arr[i]!=i)
		{
			swap((arr+i),(arr+arr[i]));
		}
		else
			continue;
	}
}
int main()
{
	int arr[]= {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
	int n=sizeof(arr)/sizeof(int);
	rearr(n,arr);
	printarr(n,arr);
	return 0;
}
