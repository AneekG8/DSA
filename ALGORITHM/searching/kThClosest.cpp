//given a sorted array and a value x find k elements closest to x existing in the array

#include<bits/stdc++.h>
using namespace std;


//we have to find the crossover point(last element greater than or equal to x )
//then we can check to its left and right


//searching for the crossover point can be optimized with binary search

int findCrossover(int arr[],int low,int high,int x)
{
    if(arr[high]<=x)
        return high;

    if(arr[low]>x)
        return low-1;

    int mid=(low+high)/2;

    if(arr[mid]<=x && arr[mid+1]>x)
        return mid;

    else if(arr[mid]<x)
        return findCrossover(arr,mid+1,high,x);

    return findCrossover(arr,low,mid-1,x);
}


void kClosest(int arr[],int n,int x,int k)
{
    int l=findCrossover(arr,0,n-1,x);

    int r=l+1;

    if(l>=0 && arr[l] == x)
        l--;    //don't take x if it exists in the array

    int count=0;

    while(l>=0 && r<n && count<k)
    {
        if(x-arr[l] < arr[r]-x)
            cout<<arr[l--]<<" ";

        else
            cout<<arr[r++]<<" ";

        count++;
    }

    //if l or r reaches boundary and we still need more elements
    while(count<k && l>=0)
        cout<<arr[l--]<<" ",count++;

    while(count<k && r<n)
        cout<<arr[r++]<<" ",count++;
}

int main()
{
    int arr[] ={12, 16, 22, 30,34, 39, 42,
                45, 48, 50, 53, 55, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 35, k = 4;
    kClosest(arr, n, x, 4);
    return 0;
}
