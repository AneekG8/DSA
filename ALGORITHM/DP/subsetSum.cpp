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

bool findSubsetDP(int arr[],int n,int sum)
{
    int table[sum+1][n];

    for(int i=0;i<=sum;i++)
    {
        for(int j=0;j<n;j++)
        {
            //include arr[j]
            bool x;

            if(arr[j]>i)
                x=false;
            else if(arr[j]==i)
                x=true;
            else
                x= j>=1 ? table[i-arr[j]][j-1] : false;

            //exclude arr[j]
            bool y= j>=1 ? table[i][j-1] : false;

            table[i][j]=x||y;
        }
    }

    return table[sum][n-1];
}

int main()
{
    int arr[] = {3,34,4,12,5, 2};

    int n = sizeof(arr)/sizeof(int);

    cout<<findSubsetDP(arr,n,30);
}
