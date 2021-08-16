//longest alternating sequence

#include<bits/stdc++.h>

using namespace std;


//DP
int las(int arr[],int n)
{
    int dp[n][2];

    dp[0][0] = 1,dp[0][1] = 1;

    int res = 1;

    for(int i=1;i<n;i++)
    {
        dp[i][0] = 1,dp[i][1] = 1;

        for(int j=i-1;j>=0;j--)
        {
            if(arr[i]>arr[j])
                dp[i][0] = max(dp[i][0],dp[j][1]+1);

            if(arr[i]<arr[j])
                dp[i][1] = max(dp[i][1],dp[j][0]+1);
        }

        res = max(dp[i][0],dp[i][1]);
    }

    return res;
}


//Linear solution
int las1(int arr[],int n)
{
    int inc = 1,dec = 1;

    for(int i=1;i<n;i++)
    {
        if(arr[i]>arr[i-1])
            inc = dec+1;
        else if(arr[i]<arr[i-1])
            dec = inc+1;
    }

    return max(inc,dec);
}
int main()
{
    int arr[] = {1, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Length of Longest alternating "
         << "subsequence is " << las1(arr, n);

    return 0;
}
