//given a sorted and rotated array find pairs with given sum
#include<iostream>
using namespace std;


void findPairs(int arr[],int n,int x)
{
    //find the pivot
    int i;

    for(i=0;i<n-1;i++)
        if(arr[i+1]<arr[i])
            break;

    int l=(i+1)%n;

    int r=i;

    while(l!=r)
    {
        if(arr[l]+arr[r]==x)
        {
            cout<<arr[l]<<" "<<arr[r]<<endl;

            if(l==(n+r-1)%n)
                break;

            l=(l+1)%n;
            r=(n+r-1)%n;
        }

        else if(arr[l]+arr[r]<x)
            l=(l+1)%n;

        else
            r=(n+r-1)%n;

        }
}


int main()
{
    int arr[] = {11, 15, 6, 7, 9, 10};
    int sum = 16;
    int n = sizeof(arr)/sizeof(arr[0]);

    findPairs(arr, n, sum);

    return 0;
}
