/*
pevious algorithms of array rotaions changed the array itself in O(n) time for the best case scenario 
the idea is to rotate(print) array multiple times without changing the array
*/
#include<stdio.h>
#include<stdlib.h>
void leftrotate(int d,int n,int *arr)				//requires extra space
{
	int i,temp[2*n];
	for(i=0;i<2*n;i++)
	{
		temp[i]=*(arr+i%n);							//the rotation gets done in O(1) time but printing takes O(n) time
	}
	for(i=d%n;i<d%n+n;i++)
	printf("%d ",temp[i]);
	printf("\n");
}
void leftrotatex(int d,int n,int *arr)				//space optimized
{
	int i;
	for(i=d%n;i<d%n+n;i++)
		printf("%d ",arr[i%n]);
	printf("\n");
}
int main()
{
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(int);
	leftrotate(14,n,arr);
	leftrotate(2,n,arr);
	leftrotate(3,n,arr);
	leftrotatex(14,n,arr);
	leftrotatex(100,n,arr);
	leftrotatex(3,n,arr);
	return 0;
}
