#include<bits/stdc++.h>
using namespace std;

int optSol(int arr[],int i,int j)
{
    if(i == j)
        return arr[i];

    if(j == i+1)
        return max(arr[i],arr[j]);

    return max(  ( arr[i] + min(optSol(arr,i+2,j),optSol(arr,i+1,j-1)) ) , ( arr[j] + min(optSol(arr,i+1,j-1),optSol(arr,i,j-2)) )  );
}

int optSolDP(int arr[],int n)
{
    int dp[n][n];

    for(int l=0;l<n;l++)
    {
        for(int i=0;i<n;i++)
        {
            int j = i+l;

            if(j > n-1)
                break;

            if(i == j)
                dp[i][j] = arr[i];

            else if(j == i+1)
                dp[i][j] = max(arr[i],arr[j]);

            else
                dp[i][j] = max((arr[i] + min(dp[i+2][j],dp[i+1][j-1])) , (arr[j] + min(dp[i+1][j-1],dp[i][j-2])));
        }
    }

    return dp[0][n-1];
}

int main()
{
    int arr1[] = { 8, 15, 3, 7 };
    int n = sizeof(arr1) / sizeof(arr1[0]);
    printf("%d\n",
           optSolDP(arr1, n));

    int arr2[] = { 2, 2, 2, 2 };
    n = sizeof(arr2) / sizeof(arr2[0]);
    printf("%d\n",
           optSol(arr2, 0,n-1));

    int arr3[] = { 20, 30, 2, 2, 2, 10 };
    n = sizeof(arr3) / sizeof(arr3[0]);
    printf("%d\n",
           optSol(arr3, 0,n-1));

    return 0;
}
