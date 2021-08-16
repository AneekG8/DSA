/*
Given an unsorted array of non negative integers, find a continuous subarray which adds to a given number.
ALGO:-
Initialize a variable curr_sum as the first element. curr_sum indicates the sum of the current subarray.
Start from the second element and add all elements one by one to the curr_sum.
If curr_sum becomes equal to the sum, then print the solution.
If curr_sum exceeds the sum, then remove trailing elements while curr_sum is greater than the sum.
*/
#include<bits/stdc++.h>
using namespace std;
void subArrSum(int *arr,int n,int sum)
{
	int i=0,j=1,curr_sum=arr[0];
	if(curr_sum==sum)
	{
		printf("found at index %d",i);
		return;
	}
	while(j<n)
	{
		curr_sum+=arr[j];
		while(curr_sum>sum)
		{
			curr_sum-=arr[i];
			i++;
		}
		if(curr_sum==sum)
		{
			if(i==j)
			{
				printf("found at index %d",i);
				return;
			}
			printf("found between index %d & %d",i,j);
			return;
		}
		j++;
	}
	if(j==n)
	{
		printf("not found!");
	}
}
int main()
{
	int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 26;
    subArrSum(arr, n, sum);
    return 0;
}
