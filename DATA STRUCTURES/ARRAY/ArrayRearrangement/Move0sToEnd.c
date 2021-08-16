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
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			int x=i;
			while(arr[x]==0 && x<n)
				x++;
			if(x==n)
				return;
			swap((arr+x),(arr+i));
		}
		else
			continue;
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
/*
ANOTHER APPROACH:
Traverse the given array ‘arr’ from left to right. While traversing, maintain count of non-zero elements in array.
Let the count be ‘count’. For every non-zero element arr[i], put the element at ‘arr[count]’ and increment ‘count’.
After complete traversal, all non-zero elements have already been shifted to front end and ‘count’ is set as index of first 0.
Now all we need to do is that run a loop which makes all elements zero from ‘count’ till end of the array.
*/
