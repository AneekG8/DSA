/*
Equilibrium index of an array is an index such that the sum of elements at lower indexes is equal to the sum of elements at higher indexes
Algo:-
The idea is to get the total sum of the array first. Then Iterate through the array and keep updating the left sum which is initialized as zero.
In the loop, we can get the right sum by subtracting the elements one by one.
*/
#include<stdio.h>
#include<stdlib.h>
int GetSum(int *arr,int n)
{
	int sum=0,i;
	for(i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	return sum;
}
int EqInd(int *arr,int n)
{
	int rsum=GetSum(arr,n),lsum=0,i;
	for(i=0;i<n;i++)
	{
		rsum-=arr[i];
		if(lsum==rsum)
			return i;
		lsum+=arr[i];
	}
	return -1;
}
int main()
{
	
    int arr[] = { -7,1,5,2,-4,3,0 }; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
    printf("First equilibrium index is %d",  EqInd(arr, arr_size)); 
    getchar(); 
    return 0; 
}
