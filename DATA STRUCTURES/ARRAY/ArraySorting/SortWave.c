/*
Sort an array in WAVE form:
Use sorting. First sort the input array, then swap all adjacent elements.
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
void sort(int n,int *arr)								//this is not an O(nlogn) sorting
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
void sortwave(int n,int *arr)
{
	int i;
	sort(n,arr);
	for(i=0;i+1<n;i+=2)
	{
		swap((arr+i),(arr+i+1));
	}
}
int main()
{
	int arr[]={20, 10, 8, 6, 4, 2};
	int n=sizeof(arr)/sizeof(int);
	sortwave(n,arr);
	printarr(n,arr);
	return 0;
}
