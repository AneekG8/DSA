//reversal algorithm to rotate an array
//time complexity O(n)
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void revarr(int start, int end,int *arr) 							//divide the array into two parts
{ 																	// A= 0 to d-1 // B= d to n-1
    int temp; 														// rotate A
    while (start < end) { 											// rotate B
        temp =*(arr+start);											// rotate whole array
		*(arr+start)=*(arr+end);
		*(arr+end)=temp;
        start++;
        end--;
    }
}
void leftrotate(int n,int d,int *arr)								// rotates to the left by d times
{
	revarr(0,d-1,arr);
	revarr(d,n-1,arr);
	revarr(0,n-1,arr);
}
void rightrotate(int n,int d,int *arr)								// rotates to the right by d times
{
	revarr(0,n-1-d,arr);
	revarr(n-d,n-1,arr);
	revarr(0,n-1,arr);
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
	int arr[]={1,2,3,4,5,6,7};
	leftrotate(7,2,arr);
	printarr(7,arr);
	printf("\n");
	int arr1[]={1,2,3,4,5,6,7};
	rightrotate(7,3,arr1);
	printarr(7,arr1);
	return 0;
}
