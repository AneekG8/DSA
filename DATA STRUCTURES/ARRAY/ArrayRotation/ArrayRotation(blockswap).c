/*
blockswap method for array rotation
time complexity: O(n)
*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void swaparr(int f,int s,int d,int *arr)			//swap two blocks of same size of an array starting from indices f and s
{
	int i;
	for(i=0;i<d;i++)
	{
		swap((arr+f+i),(arr+s+i));
	}
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
void leftrotate(int d,int n,int *arr)
{
	int i;
	if(d==0||d==n)
	{
		printarr(n,arr);
		return;
	}
	else if(d==n-d)											//divides the array into two equal blocks and swaps them
	{
		swaparr(0,d,d,arr);
	}
	else if(d<n-d)
	{														// Initialize A = arr[0..d-1] and B = arr[d..n-1]
		swaparr(0,n-d,d,arr);								// 1) Do following until size of A is equal to size of B
		leftrotate(d,n-d,arr);								  // a)  If A is shorter, divide B into Bl and Br such that Br is of same
	}													    	//   length as A. Swap A and Br to change ABlBr into BrBlA. Now A
	else 													    //   is at its final place, so recur on pieces of B.
	{														  // b)  If A is longer, divide A into Al and Ar such that Al is of same
		swaparr(0,d,n-d,arr);								    //   length as B Swap Al and B to change AlArB into BArAl.
		leftrotate(2*d-n,d,arr+n-d);						  //     Now Bis at its final place, so recur on pieces of A.
	}
}															// 2) Finally when A and B are of equal size, block swap them.


void leftrotate1(int d,int n,int arr[])
{
	if(d==0||d==n)
	{
		//printarr(n,arr);
		return;
	}
	else if(d==n-d)											//divides the array into two equal blocks and swaps them
	{
		swaparr(0,d,d,arr);
	}

	else if(d < n-d)
    {
        swaparr(0,d,d,arr);
        leftrotate1(d,n-d,arr+d);
    }

    else
    {
        swaparr(2*d-n,d,n-d,arr);
        leftrotate1(2*d-n,d,arr);
    }
}

int main()
{
	int i,n,d,arr[]={1,2,3,4,5,6,7,8,9,10};
	leftrotate1(9,10,arr);
	printarr(10,arr);
	return 0;
}
