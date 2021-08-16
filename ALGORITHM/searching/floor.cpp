//find floor of a number in a sorted  array

#include<iostream>
using namespace std;

int floor(int arr[],int l,int h,int x)
{
    if(h>=l)
    {
        if(l==h && arr[l]<=x)
            return l;

        int mid = (h+l)/2;

        if(arr[mid]<=x && arr[mid+1]>x)
            return mid;

        else if(arr[mid]>x)
            return floor(arr,l,mid-1,x);

        else
            return floor(arr,mid+1,h,x);
    }

    return -1;
}

int main()
{
    int arr[] = { 1, 2, 4, 6, 10, 12, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;
    int index = floor(arr, 0, n - 1, x);
    //cout<<index<<endl;
    if (index == -1)
        printf(
            "Floor of %d doesn't exist in array ", x);
    else
        printf(
            "Floor of %d is %d", x, arr[index]);
    return 0;
}
