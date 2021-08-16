#include<bits/stdc++.h>

using namespace std;


int maxSegments(int l,int p,int q,int r)
{
    int dp[l+1];

    memset(dp,-1,sizeof(dp));

    dp[0] = 0;

    for(int i=0;i<l+1;i++)
    {
        if(dp[i] == -1)
            continue;

        if(i+p<=l)
            dp[i+p] = max(dp[i+p],dp[i]+1);

        if(i+q<=l)
            dp[i+q] = max(dp[i+q],dp[i]+1);

        if(i+r<=l)
            dp[i+r] = max(dp[i+r],dp[i]+1);
    }

    if(dp[l] == -1)
        return dp[l] = 0;

    return dp[l];
}
int main()
{
    cout<<maxSegments(11,2,3,5);
}
