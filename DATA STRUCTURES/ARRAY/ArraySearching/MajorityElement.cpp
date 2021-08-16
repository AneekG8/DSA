/*
Write a function which takes an array and prints the majority element (if it exists), otherwise prints “No Majority Element”.
A majority element in an array A[] of size n is an element that appears more than n/2 times (and hence there is at most one such element).
*/
#include<bits/stdc++.h>
using namespace std;
void printarr(int *arr,int n)
{
	int i=0;
	while(n--)
	{
		printf("%d ",arr[i++]);
	}
	printf("\n");
}
int candidate(int *arr,int n)			//Moore's voting algo: returns an element which could possibly be a major element(required condition for major element)
{
	int i,maj_ind=0,count=1;
	for(i=1;i<n;i++)
	{
		if(arr[i]==arr[maj_ind])
		{
			count++;
		}
		else
		{
			count--;
		}
		if(count==0)
		{
			maj_ind=i;
			count=1;
		}
	}
	return arr[maj_ind];
}
bool ismajor(int *arr,int n,int val)					//checks if the returned candidate is a major element
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==val)
			count++;
		else continue;
	}
	if(count>n/2)
		return true;
	else
		return false;
}
void printMajority(int *arr,int n)
{
	if(ismajor(arr,n,candidate(arr,n)))
		printf("Majority element is: %d\n",candidate(arr,n));
	else
		printf("No majority element\n");
}
int main()
{
	int a[] = {3,4,3,5,6,3,3,3,7}; 
    int size = (sizeof(a))/sizeof(a[0]);
    printMajority(a, size);
    return 0;
}
