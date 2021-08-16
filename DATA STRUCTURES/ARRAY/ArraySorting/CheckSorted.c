#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)					
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int check(int n,int *arr,int *b)
{
	int i,ret=1;
	for(i=0;i<n-1;i++)
	{
		if(b[i])
		{
			swap((arr+i),(arr+i+1));
		}
		else
			continue;
	}
	for(i=0;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			ret=0;
			break;
		}
		else
			continue;
	}
	return ret;
}
int main()
{
	int A[] = {2, 3, 1, 4, 5, 6};
    int B[] = {0, 1, 1, 1, 1};
    int n = sizeof(A) / sizeof(A[0]); 
	if(check(n,A,B))
		printf("can be sorted\n");
	else
		printf("can't be sorted\n");
	return 0;
}
