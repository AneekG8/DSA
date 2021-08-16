/*
Check if a given number is a majority element in a sorted array
*/
#include<bits/stdc++.h>
using namespace std;
int binarysearch(int *arr,int low,int high,int x)
{
if (high >= low)
    {
        int mid = (low + high)/2; /*low + (high - low)/2;*/

        /* Check if arr[mid] is the first occurrence of x.
            arr[mid] is first occurrence if x is one of the following
            is true:
            (i) mid == 0 and arr[mid] == x
            (ii) arr[mid-1] < x and arr[mid] == x
        */
        if ( (mid == 0 || x > arr[mid-1]) && (arr[mid] == x) )
            return mid;
        else if (x > arr[mid])
            return binarysearch(arr, (mid + 1), high, x);
        else
            return binarysearch(arr, low, (mid -1), x);
    }

    return -1;
}
bool ismajor(int *arr,int n,int x)
{
	int ind=binarysearch(arr,0,n-1,x);		//first index of occurrence of x
	if((ind+n/2) <= (n-1) && arr[ind+n/2]==x)		//IMPORTANT!
		return true;
	else
		return false;
}
void printMajor(int *arr,int n,int x)
{
	if(ismajor(arr,n,x))
		printf("%d is a major element",x);
	else
		printf("%d is not a major element",x);
}
int main()
{
	int arr[] = {1, 2, 3, 3, 3, 3, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
	printMajor(arr,n,3);
    return 0;
}
