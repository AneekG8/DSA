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
int minswap(int k,int n,int *arr)
{
	int i,j=-1,swapc=0;
	for(i=0;i<n;i++)
	{
		if(arr[i]<=k)
		{
			j++;
			if(i==j)
				continue;
			swap((arr+j),(arr+i));
			swapc++;
		}
	}
	return swapc;
}
int main()
{
	int arr[]={2, 7, 9, 5, 8, 7, 4};
	int n=sizeof(arr)/sizeof(int);
	printf("%d\n",minswap(5,n,arr));
	printarr(n,arr);
	return 0;
}
