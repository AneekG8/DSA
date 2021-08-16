#include<bits/stdc++.h>

using namespace std;

int lrsUtil(int x, int y, string s1, string s2,vector<vector<int>> dp)
    {
        if(dp[x][y] != -1)
            return dp[x][y];

        if(x == 0 || y==0)
            return dp[x][y] = 0;

        // your code here
        if(s1[s1.size()-x] == s2[s2.size()-y] && s1.size()-x != s2.size()-y)
            return dp[x][y] = 1+lrsUtil(x-1,y-1,s1,s2,dp);

        else
            return dp[x][y] = max(lrsUtil(x,y-1,s1,s2,dp),lrsUtil(x-1,y,s1,s2,dp));
    }

    int lrsDP(int x,int y,string s1,string s2)
    {
        int dp[x+1][y+1];

        for(int i=0;i<=x;i++)
            dp[i][0] = 0;

        for(int i=0;i<=y;i++)
            dp[0][i] = 0;

        for(int i=1;i<=x;i++)
        {
            for(int j=1;j<=y;j++)
            {
                if(s1[i-1] == s2[j-1] && i != j)
                    dp[i][j] = 1+dp[i-1][j-1];

                else
                    dp[i][j] = max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
            }
        }

        return dp[x][y];
    }

    int lrs(string s)
    {
        //vector<vector<int>> dp(x+1,vector<int>(y+1,-1));

        return lrsDP(s.size(),s.size(),s,s);
    }

    int main()
    {
        string s = "aaab";

        cout<<lrs(s);
    }


