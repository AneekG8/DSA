/*
Given an array, find an element before which all elements are smaller than it,
and after which all are greater than it. Return the index of the element if there is such an element, otherwise, return -1.
*/

#include<iostream>
using namespace std;

int findElement(int arr[],int n)
{
    if(n==1 || n==2)
        return -1;

    //find left max array
    int leftMax[n];
    int lm=INT_MIN;
    leftMax[0]=INT_MIN;

    for(int i=1;i<n;i++)
    {
        lm=max(arr[i-1],lm);
        leftMax[i]=lm;
    }

    int rm=INT_MAX; //right minimum

    for(int i=n-2;i>=1;i--)
    {
        rm=min(rm,arr[i+1]);

        if(leftMax[i]<arr[i] && arr[i]<rm)
            return i;
    }

    return -1;
}
int main()
{
    int arr[] = {5, 1, 4, 3, 6, 8, 10, 7, 9};
    int n = sizeof arr / sizeof arr[0];
    cout << "Index of the element is " << findElement(arr, n);
    return 0;
}
