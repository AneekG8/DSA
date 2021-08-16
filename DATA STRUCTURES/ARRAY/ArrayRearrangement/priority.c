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
	printf("\n");
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void prio(int n,int *ind,int *arr)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(*(ind+i)>*(ind+j))
			{
				swap((arr+*(ind+i)),(arr+*(ind+j)));			//we are rearranging the array according to sorted index array
			}													//with this approach we can't modify(sort) the index array simultaneously
		}														//But if we use heapsort then we can modify both the arrays
	}
}
int main()
{
	int arr[]={10,11,12,15,18,19};
	int ind[]={1,0,2,4,5,3};
	int n=sizeof(arr)/sizeof(int);
	prio(n,ind,arr);
	printarr(n,arr);
	return 0;
}
