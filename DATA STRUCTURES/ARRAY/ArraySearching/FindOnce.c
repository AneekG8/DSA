//find the element which appears only once in an array while all the other elements appear twice
#include<stdio.h>
int findonce(int *arr,int n)				//returns the only number that occurs once in an array where all the other numbers occur twice
{
	int i,res=arr[0];
	for(i=1;i<n;i++)
	{
		res=res^arr[i];						//XOR of any two same numbers is 0 thus only number remaining would be the number occuring once
	}
	return res;
}

//other alternatives:
//Brute Force to find count of each element n^2
//sort and find count nlogn
//hashing to find frequency n with extra space

int main()
{
	int arr[]={1,1,2,3,3,4,5,5,4,2,6,7,6};
	int n=sizeof(arr)/sizeof(int);
	printf("%d\n",findonce(arr,n));
	return 0;
}
