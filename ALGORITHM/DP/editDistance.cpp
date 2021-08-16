#include<bits/stdc++.h>
using namespace std;

int editDistanceRecur(string str1,string str2,int i,int j)
{
    static int l1 = str1.length();
    static int l2 = str2.length();

    if(i == l1)
        return l2-j;

    if(j == l2)
        return l1-i;

    if(str1[i] == str2[j])
        return editDistanceRecur(str1,str2,i+1,j+1);

    else
        return 1 + min(min(editDistanceRecur(str1,str2,i,j+1),editDistanceRecur(str1,str2,i+1,j+1)),editDistanceRecur(str1,str2,i+1,j));
}

int editDistanceRecurMemUtil(string s,string t,int sl,int tl,vector<vector<int>> dp)
    {
        if(!sl) return tl;

        if(!tl) return sl;

        if(dp[sl][tl] != -1) return dp[sl][tl];

        if(s[sl-1] == t[tl-1])
        {
            if(dp[sl-1][tl-1] != -1)
                return dp[sl][tl] = dp[sl-1][tl-1];

            return dp[sl][tl] = editDistanceRecurMemUtil(s,t,sl-1,tl-1,dp);

        }

        int ins = 1+editDistanceRecurMemUtil(s,t,sl,tl-1,dp);

        int rem = 1+editDistanceRecurMemUtil(s,t,sl-1,tl,dp);

        int rep = 1+editDistanceRecurMemUtil(s,t,sl-1,tl-1,dp);

        return dp[sl][tl] = min(ins,(min(rem,rep)));
    }

int editDistanceRecurMem(string s,string t)
{
    vector<vector<int>> dp(s.size()+1,vector<int>(t.size()+1,-1));

    return editDistanceRecurMemUtil(s,t,s.size(),t.size(),dp);
}

int editDistanceDP(string s,string t)
    {
        int sl = s.size(), tl = t.size();

        int dp[sl+1][tl+1];

        for(int i=0;i<=sl;i++)
        {
            for(int j=0;j<=tl;j++)
            {
                if(i == 0)
                    dp[i][j] = j;

                else if(j == 0)
                    dp[i][j] = i;

                else if(s[i-1] == t[j-1])
                    dp[i][j] = dp[i-1][j-1];

                else
                    dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));

            }
        }

        return dp[sl][tl];
    }
int main()
{
    string str1 = "sunday";

    string str2 = "saturday";

    cout<<editDistanceDP(str1,str2);
}
