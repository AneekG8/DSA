/*
Given an unsorted array arr[0..n-1] of size n, find the minimum length subarray arr[s..e] such that sorting this subarray makes the whole array sorted.

1) Find the candidate unsorted subarray
a) Scan from left to right and find the first element which is greater than the next element. Let s be the index of such an element.
In the above example 1, s is 3 (index of 30).
b) Scan from right to left and find the first element (first in right to left order) which is smaller than the next element (next in right to left order).
Let e be the index of such an element. In the above example 1, e is 7 (index of 31).





2) Check whether sorting the candidate unsorted subarray makes the complete array sorted or not. If not, then include more elements in the subarray.
a) Find the minimum and maximum values in arr[s..e]. Let minimum and maximum values be min and max.
min and max for [30, 25, 40, 32, 31] are 25 and 40respectively.
b) Find the first element (if there is any) in arr[0..s-1] which is greater than min, change s to index of this element.
There is no such element in above example 1.
c) Find the last element (if there is any) in arr[e+1..n-1] which is smaller than max, change e to index of this element.
In the above example 1, e is changed to 8 (index of 35)

3) Print s and e.
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
	printf("\n");
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int l,int r,int *arr)
{
	int i,j;
	for(i=l;i<=r;i++)
	{
		for(j=i;j<=r;j++)
		{
			if(arr[i]>arr[j])
				swap((arr+i),(arr+j));
		}
	}
}
int checksort(int n,int *arr)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(arr[i]<arr[i+1])
			continue;
		else break;
	}
	return i==n-1;
}
void printUnsorted(int n,int *arr)
{
	int i,j;
	for(i=0;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
			break;
		else continue;
	}
	if(i==n-1)
	{
		printf("the array is already sorted\n");
		return;
	}
	for(j=n-1;j>0;j--)
	{
		if(arr[j]<arr[j-1])
			break;
		else continue;
	}
	sort(i,j,arr);
	if(checksort(n,arr))
	{
		printf("between indeces %d and %d\n",i,j);
		return;
	}
	else
	{
		int l,r;
		for(l=0;l<i;l++)
		{
			if(arr[l]>arr[i])
				break;
		else continue;
		}
		for(r=n-1;r>j;r--)
		{
			if(arr[r]<arr[j])
				break;
			else continue;
		}
		printf("between indeces %d and %d\n",l,r);
		sort(l,r,arr);
		printarr(n,arr);
		//printUnsorted(n,arr);
	}

}
int main()
{
	int arr[]={10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
	int n=sizeof(arr)/sizeof(int);
	printUnsorted(n,arr);
	return 0;
}
