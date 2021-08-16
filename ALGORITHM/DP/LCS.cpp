#include<bits/stdc++.h>

using namespace std;

int lcsUtil(int x, int y, string s1, string s2,vector<vector<int>> dp)
    {
        if(dp[x][y] != -1)
            return dp[x][y];

        if(x == 0 || y==0)
            return dp[x][y] = 0;

        // your code here
        if(s1[s1.size()-x] == s2[s2.size()-y])
            return dp[x][y] = 1+lcsUtil(x-1,y-1,s1,s2,dp);

        else
            return dp[x][y] = max(lcsUtil(x,y-1,s1,s2,dp),lcsUtil(x-1,y,s1,s2,dp));
    }

    int lcsDP(int x,int y,string s1,string s2)
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
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];

                else
                    dp[i][j] = max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
            }
        }

        return dp[x][y];
    }

    int lcsDPSpaceOpt(int x,int y,string s1,string s2)
    {
        int dp[2][y+1];

        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                if(i==0 || j==0)
                    dp[i%2][j] = 0;

                else if(s1[i-1] == s2[j-1])
                    dp[i%2][j] = 1+dp[(i+1)%2][j-1];
                else
                    dp[i%2][j] = max(dp[(i+1)%2][j],dp[i%2][j-1]);
            }
        }

        return dp[x%2][y];
    }

    int lcs(int x,int y,string s1,string s2)
    {
        //vector<vector<int>> dp(x+1,vector<int>(y+1,-1));

        return lcsDPSpaceOpt(x,y,s1,s2);
    }

    int main()
    {
        string s1 = "aggtab";

        string s2 = "gxtxayb";

        cout<<lcs(s1.length(),s2.length(),s1,s2);
    }

