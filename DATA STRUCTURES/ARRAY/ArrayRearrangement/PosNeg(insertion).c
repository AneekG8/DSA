/*
Rearrange an array in a way such that all the neg numbers are at the begining of the array followed by the pos numbers keeping the order same.
Algo:
.ignore the first element
.traverse from arr[1]
.if positive ignore
.if negative we store it in temp and shift all the preceeding POSITIVE elements to right by 1 positon
.we store temp back to the index from where the shifting(of pos numbers) started
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
	int i,j,temp;
	{
		for(i=1;i<n;i++)
		{
			if(arr[i]>0)
				continue;
			else
			{
				temp=arr[i];						//the approach is similar to  insertion sort
				j=i-1;
				while(arr[j]>0 && j>=0)
				{
					arr[j+1]=arr[j];
					j--;
				}
				arr[j+1]=temp;
			}
		}
	}
}

int main()
{
	int arr[]={1,2,3,-4,-6,-5};
	int n=sizeof(arr)/sizeof(int);
	rearr(n,arr);
	printarr(n,arr);
	return 0;
}
