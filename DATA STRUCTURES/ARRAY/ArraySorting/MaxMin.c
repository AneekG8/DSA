/*
Given an array of integers, print the array in such a way that the first element is first maximum and second element is first minimum and so on.

1) Sort input array using a O(n Log n) algorithm.
2) We maintain two pointers, one from beginning and one from end in sorted array.
We alternatively print elements pointed by two pointers and move them toward each other.
*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int n,int *arr)									//this is not an O(nlogn) sorting
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
void modify(int n,int *arr)
{
	int max=n-1,min=0;
	sort(n,arr);
	while(min<max)
	{
		printf("%d %d ",arr[max],arr[min]);
		min++;
		max--;
	}
	if(min == max)
		printf("%d",arr[min]);
}
int main()
{
	int arr[]={7,3,4,5,1,6,2};
	int n=sizeof(arr)/sizeof(int);
	modify(n,arr);
	return 0;
}
