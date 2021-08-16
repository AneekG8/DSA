/*
SHUFFLE A GIVEN ARRAY:
Fisher–Yates shuffle Algorithm works in O(n) time complexity. The assumption here is, we are given a function rand() that generates random number in O(1) time.
The idea is to start from the last element, swap it with a randomly selected element from the whole array (including last).
Now consider the array from 0 to n-2 (size reduced by 1), and repeat the process till we hit the first element.
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
void shuffle(int n,int *arr)
{
	srand(time(0));					//srand(seed) sets the seed value for rand() to generate random numbers
	if(n==1)						//time(t) returns different value each time
		return;
	swap(&arr[n-1],&arr[rand()%(n-1)]);
	shuffle(n-1,arr);
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8};
	int n=sizeof(arr)/sizeof(int);
	shuffle(n,arr);
	printarr(n,arr);
	return 0;
}
