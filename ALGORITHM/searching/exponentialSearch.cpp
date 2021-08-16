//we look for the shorter window(for binary search) by checking in the range twice than the previous

#include<iostream>
using namespace std;

int binarySearch(int arr[],int l,int r,int x)
{
    if(r>=l)
    {
        int mid=(l+r)/2;

        if(arr[mid]==x)
            return mid;

        else if (x<arr[mid])
            return binarySearch(arr,l,mid-1,x);

        return binarySearch(arr,mid+1,r,x);
    }

    return -1;
}

int expSearch(int arr[],int n,int x)
{
    if(arr[0]==x)
        return 0;

    if(x>arr[n-1])
        return -1;

    int i=1;    //start form index 1 with window size 1

    while(i<n && arr[i]<=x)
        i=i*2;

    return binarySearch(arr,i/2,min(i,n)-1,x);
}

int main()
{
   int arr[] = {2, 3, 4, 10,15,40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 15;
   int result = expSearch(arr, n, x);
   (result == -1)? printf("Element is not present in array")
                 : printf("Element is present at index %d",
                                                    result);
   return 0;

}
