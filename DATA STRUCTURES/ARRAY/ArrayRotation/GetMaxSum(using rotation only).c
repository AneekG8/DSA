/*
find the max value of sum of i*arr[i] for all the rotations of the array
Time complexity: O(n^2)
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
void leftrotate1(int n,int *arr)
{
	int i,temp=*arr;
	for(i=0;i<n-1;i++)
	{
		*(arr+i)=*(arr+i+1);
	}
	*(arr+n-1)=temp;
}
int getsum(int n,int *arr)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum += i*arr[i];
	}
	return sum;
}
int getmaxsum(int n,int *arr)
{
	int i,maxsum=getsum(n,arr);
	for(i=1;i<n;i++)
	{
		leftrotate1(n,arr);
		if(maxsum < getsum(n,arr))
			maxsum = getsum(n,arr);
	}
	return maxsum;
}
int main()
{
	int arr[]={10,1,2,3,4,5,6,7,8,9};
	int n=sizeof(arr)/sizeof(int);
	printf("%d\n",getmaxsum(n,arr));
	return 0;
}
