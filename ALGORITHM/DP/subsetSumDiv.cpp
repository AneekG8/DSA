#include<iostream>
using namespace std;

bool findSubsetRecur(int arr[],int n,int sum)
{
    if(sum==0)
        return true;

    if(sum<0)
        return false;

    if(n<=0 && sum>0)
        return false;

    return findSubsetRecur(arr+1,n-1,sum) || findSubsetRecur(arr+1,n-1,sum-arr[0]);
}

bool findSubsetSumDiv(int arr[],int n,int m)
{
    int sum=0;

    for(int i=0;i<n;i++)
        sum+=arr[i];

    int d=sum/m;

    for(int i=1;i<=d;i++)
        if(findSubsetRecur(arr,n,i*m))
            return true;

    return false;
}

int main()
{
    int arr[] = {3,1,7};

    int n = sizeof(arr)/sizeof(int);

    cout<<findSubsetSumDiv(arr,n,9);
}

