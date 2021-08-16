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
void del(int ind,int n,int *arr)
{
	int i;
	for(i=ind;i<n-1;i++)
	{
		arr[ind]=arr[ind+1];
	}
	//free(arr+n-1);
}
void shuffle(int n,int *arr)
{
	int temp[n],i,ind,num;
	num=n;
	for(i=0;i<n;i++)
	{
		temp[i]=arr[i];
	}
	for(i=0;i<n;i++)
	{
		ind=rand()%num;
		arr[i]=temp[ind];
		del(ind,num,temp);
		num=num-1;
	}
}
int main()
{
	int arr[]={1,2,3,4,5,6,7,8};
	int n=sizeof(arr)/sizeof(int);
	shuffle(n,arr);
	printarr(n,arr);
	return 0;
}
