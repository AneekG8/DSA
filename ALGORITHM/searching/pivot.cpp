//Given an array of integers which is initially increasing and then decreasing, find the maximum value in the array.

#include<iostream>
using namespace std;

int findPivot(int arr[],int l,int h)
{
    if(l==h)
        return l;

    if(h==l+1 && arr[h]>arr[l])
        return h;

    if(h==l+1 && arr[h]<arr[l])
        return l;

    int mid=l+(h-l)/2;

    if(arr[mid]>arr[mid+1] && arr[mid]>arr[mid-1])
        return mid;

    else if(arr[mid]>arr[mid+1])
        return findPivot(arr,l,mid-1);

    return findPivot(arr,mid+1,h);
}

int main()
{
    int arr[]={80,90,500,3,2,1};

    int n=sizeof(arr)/sizeof(n);

    cout<<arr[findPivot(arr,0,n-1)];

    return 0;

}
