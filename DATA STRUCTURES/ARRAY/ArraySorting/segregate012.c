/*
3 WAY PARTITION:
The problem is similar to our old post Segregate 0s and 1s in an array, and both of these problems are variation of famous Dutch national flag problem.

The problem was posed with three colours, here `0', `1' and `2'. The array is divided into four sections:

a[1..Lo-1] zeroes (red)
a[Lo..Mid-1] ones (white)
a[Mid..Hi] unknown
a[Hi+1..N] twos (blue)
The unknown region is shrunk while maintaining these conditions

Lo := 1; Mid := 1; Hi := N;
while Mid <= Hi do
Invariant: a[1..Lo-1]=0 and a[Lo..Mid-1]=1 and a[Hi+1..N]=2; a[Mid..Hi] are unknown.
case a[Mid] in
0: swap a[Lo] and a[Mid]; Lo++; Mid++
1: Mid++
2: swap a[Mid] and a[Hi]; Hi–-
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
void segregate012(int lo,int mid,int hi,int n,int *arr)
{
	while(mid<=hi)
	{
		if(arr[mid]==0)
		{
			swap((arr+lo),(arr+mid));
			lo++;
			mid++;
		}
		else if(arr[mid]==1)
		{
			mid++;
		}
		else
		{
			swap((arr+hi),(arr+mid));
			hi--;
		}
	}
}
int main()
{
	int arr[]={0,1,2,0,0,1,1,2,1,2,2,0};
	int n=sizeof(arr)/sizeof(int);
	segregate012(0,0,n-1,n,arr);
	printarr(n,arr);
	return 0;
}
