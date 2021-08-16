#include<stdio.h>
#include<stdlib.h>
void rearr(int n,int *arr)
{
	int i,temp[n];
	for(i=0;i<n;i++)
	{
		temp[i]=arr[i];
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]!=-1)
			arr[temp[i]]=temp[i];
		else
			continue;
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]!=i)
			arr[i]=-1;
		else 
			continue;
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
int main()
{
	int arr[]= {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
	int n=sizeof(arr)/sizeof(int);
	rearr(n,arr);
	printarr(n,arr);
	return 0;
}
