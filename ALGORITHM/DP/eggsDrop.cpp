#include<bits/stdc++.h>

using namespace std;

int eggsDropUtil(int n,int k,vector<vector<int>> dp)
{
    if(dp[n][k] != -1)
        return dp[n][k];

    if(k == 1 || k == 0)
        return dp[n][k] = k;

    if(n == 1)
        return dp[n][k] = k;

    int res = INT_MAX;

    for(int x=1; x<=k; x++)
        res = min(res,1+max(eggsDropUtil(n-1,x-1,dp),eggsDropUtil(n,k-x,dp)));

    return dp[n][k] = res;
}

int eggsDropDP(int n,int k)
{
    int dp[n+1][k+1];

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            if(j == 1 || j == 0 || i == 1)
                dp[i][j] = j;
            else
            {
                dp[i][j] = INT_MAX;

                for(int x=1; x<=j;x++)
                    dp[i][j] = min(dp[i][j],1+max(dp[i-1][x-1],dp[i][j-x]));
            }
        }
    }

    return dp[n][k];
}

int eggsDrop(int n,int k)
{
    //vector<vector<int>> dp(n+1,vector<int>(k+1,-1));

    //return eggsDropUtil(n,k,dp);

    return eggsDropDP(n,k);
}

int main()
{
    cout<<eggsDrop(2,36);
}
