//given an array find any peak element in it (an element which is greater than its neighbor(s)

#include<iostream>
using namespace std;

int findPeak(int arr[],int l,int h,int n)
{
    int mid=(l+h)/2;

    //if mid is a peak
    if((mid==0 || arr[mid]>=arr[mid-1]) && (mid==n-1 || arr[mid]>=arr[mid+1]))
        return mid;

    //if mid-1 > mid there must be a peak at left
    else if(mid!=0 && arr[mid]<arr[mid-1])
        return findPeak(arr,l,mid-1,n);

    else    //mid will never become n-1 so we don't need to check that corner case
        return findPeak(arr,mid+1,h,n);
}

int findPeak(int arr[],int n)
{
    return findPeak(arr,0,n-1,n);
}

int main()
{
    int arr[] = { 1, 3, 20, 4, 1, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Index of a peak point is "
         << findPeak(arr, n);
    return 0;
}
