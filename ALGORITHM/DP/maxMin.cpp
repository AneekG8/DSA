#include<bits/stdc++.h>
using namespace std;

/*
Given N integers and K, find the minimum number of elements that should be removed, such that Amax-Amin<=K.
After the removal of elements, Amax and Amin is considered among the remaining elements.
*/

//DP O(n^2)
int minMovesRecur(int arr[],int l,int r,int k,vector<vector<int>> dp)
{
    if(l>r)
        return INT_MAX;

        if(dp[r][l] != -1)
            return dp[r][l];

    if(arr[r]-arr[l] <= k)
        return dp[r][l] == 0;

    int subres = min(minMovesRecur(arr,l+1,r,k,dp),minMovesRecur(arr,l,r-1,k,dp));

    return dp[r][l] = subres == INT_MAX ? subres : 1+subres;
}


//find index
int findInd(int arr[],int l,int r,int k)
{
    if(l<=r)
    {
        int mid = (l+r)/2;

        if(arr[mid] < k)
            return max(mid,findInd(arr,mid+1,r,k));

        else if(arr[mid] == k)
            return mid;

        else
            return findInd(arr,l,mid-1,k);
    }

    return -1;
}

//O(nlogn)
int minMoves2(int arr[],int n,int k)
{
    sort(arr,arr+n);

    int min_moves = INT_MAX;

    for(int i=0;i<n-1;i++)
    {
        int ind = findInd(arr,i+1,n-1,arr[i]+k);

        int moves = ind == -1 ? INT_MAX : n-(ind-i+1);

        min_moves = min(min_moves,moves);

    }

    return min_moves;
}


//O(n)




int minMoves(int arr[],int n,int k)
{
    vector<vector<int>> dp(n,vector<int>(n,-1));

    sort(arr,arr+n);

    return minMovesRecur(arr,0,n-1,k,dp);
}

int main()
{
    int a[] = {1, 5, 6, 2, 8};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 2;
    cout << minMoves2(a,n,k);
    return 0;
}
