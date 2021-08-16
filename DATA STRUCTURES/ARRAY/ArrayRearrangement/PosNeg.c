/*
Rearrange the array in alternate sequence of pos and neg numbers
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
void rearr(int n,int *arr)
{
	int i=-1;
	int j;
	for(j=0;j<n;j++)
	{
		if(arr[j]<0)								//0 is pivot
		{
			i++;
			swap((arr+i),(arr+j));
		}
	}
	int pos=i+1,neg=0;
	while(pos<n && neg<pos && arr[neg]<0)			//important
	{
		swap((arr+pos),(arr+neg));
		pos++;
		neg+=2;
	}
}
int main()
{
	int arr[]={-1, 2, 3,-4,5,6,7};
	int n=sizeof(arr)/sizeof(int);
	rearr(n,arr);
	printarr(n,arr);
	return 0;
}
