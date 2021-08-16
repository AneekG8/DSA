//check if a given array can represent a binary heap or not

#include<iostream>
using namespace std;


//!method 1 recursive

bool isHeapRecur(int arr[],int i,int n)
{
    //last parent node is n/2-1  (last leaf node at n-1 so parent(n-1)=(n-1-1)/2
    if(i>(n/2-1))
        return true;

    if( arr[i]<arr[2*i+1] || (( 2*i+2)<n && arr[i]<arr[2*i+2]) )    //right child may not exist
        return false;

    return isHeapRecur(arr,2*i+1,n) && isHeapRecur(arr,2*i+2,n);
}



//!method 2 iterative
bool isHeapItr(int arr[],int n)
{
    for(int i=0;i<=(n/2-1);i++)
    {
        if( arr[i]<arr[2*i+1] || (( 2*i+2)<n && arr[i]<arr[2*i+2]) )    //!right child may not exist
            return false;
    }

    return true;
}

int main()
{
    int arr[] = {90, 15, 10, 7, 12,8};
    int n = sizeof(arr) / sizeof(int);

    isHeapItr(arr, n)? printf("Yes"): printf("No");

    return 0;
}


