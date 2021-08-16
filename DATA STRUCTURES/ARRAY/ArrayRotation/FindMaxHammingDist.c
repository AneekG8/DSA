/*
Find the maximum hamming distance of an array and its rotated versions:

Create another array which is double the size of the original array, such that the elements of this new array (copy array) are just the elements of the original array repeated twice in the same sequence. Example, if the original array is 1 4 1, then the copy array is 1 4 1 1 4 1.
Now, iterate through the copy array and find hamming distance with every shift (or rotation). So we check 4 1 1, 1 1 4, 1 4 1, choose the output for which the hamming distance is maximum.

Time Complexity: O(n*n)
*/
#include<stdio.h>
#include<stdlib.h>
void leftrotate1(int n,int *arr)
{
	int i,temp=*arr;
	for(i=0;i<n-1;i++)
	{
		*(arr+i)=*(arr+i+1);
	}
	*(arr+n-1)=temp;
}
int  findmaxham(int n,int *arr)
{
	int i,j,maxham=0;
	int temp[2*n];
	for(i=0;i<2*n;i++)
	{
		temp[i]=*(arr+i%n);
	}
	for(i=1;i<n;i++)
	{
		int d=0,c=0;
		//leftrotate1(n,temp);
		for(j=i;j<i+n;j++)
		{
			if(temp[j]!=arr[c++])
				d++;
			else
				continue;
		}
		if(d>maxham)
			maxham=d;
	}
	return maxham;
}
int main()
{
	int arr[]={2,4,2};
	int n=sizeof(arr)/sizeof(int);
	printf("%d\n",findmaxham(n,arr));
	return 0;
}
