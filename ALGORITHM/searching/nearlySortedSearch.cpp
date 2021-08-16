//search in an array which is sorted but after sorting some of the elements are swapped with any of its neighbors

#include<iostream>
using namespace std;


int binarySearch(int arr[],int l,int h,int x)   //modified
{
    if(h>=l)
    {
        int mid =(l+h)/2;

        if(arr[mid]==x)
            return mid;

        else if(mid+1<=h && arr[mid+1]==x)
            return mid+1;

        else if(mid-1>=l && arr[mid-1]==x)
            return mid-1;

        else if(arr[mid]<x)
            return binarySearch(arr,mid+2,h,x);

        return binarySearch(arr,l,mid-2,x);
    }

    return -1;
}

int main()
{
    int arr[] = {3, 2, 10, 4, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
                   : printf("Element is present at index %d",
                             result);
    return 0;
}
