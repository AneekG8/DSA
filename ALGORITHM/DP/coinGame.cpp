/*
A and B are playing a game. At the beginning there are n coins. Given two more numbers x and y.
In each move a player can pick x or y or 1 coins. A always starts the game.
The player who picks the last coin wins the game or the person who is not able to pick any coin loses the game.
For a given value of n, find whether A will win the game or not if both are playing optimally.
*/

#include<bits/stdc++.h>

using namespace std;

/*bool resultHelp(int n,bool turnB,int x,int y)
{
    if(!turnB && n == 0)
        return false;

    if(turnB && n == 0)
        return true;

    bool f=false,s=false,t=false;

    if(n>=1)
        f = resultHelp(n-1,!turnB,x,y);

    if(n>=x)
        s = resultHelp(n-x,!turnB,x,y);

    if(n>=y)
        t = resultHelp(n-y,!turnB,x,y);

    return f||s||t;
}

bool resultDP(int n,int x,int y)
{
    int dp[2][n+1];

    memset(dp,-1,sizeof(dp));

    for(int j=0; j<=n;j++)
    {
        for(int i=0;i<=1;i++)
        {
            if(j == 0)
                dp[i][j] = i;
            else
            {
                bool f=false,s=false,t=false;

                if(j>=1)
                    f = dp[!i][j-1];

                if(j>=x)
                    s = dp[!i][j-x];

                if(j>=y)
                    t = dp[!i][j-y];

            }
        }
    }

    return dp[0][n];
}

bool result(int n,int x,int y)
{
    return resultHelp(n,false,x,y);
}*/

bool findWinner(int n,int x,int y)
{
    bool dp[n+1];

    dp[0] = 0,dp[1] = 1;

    for(int i=2;i<=n;i++)
    {
        if(i-1 >=0 && !dp[i-1])
            dp[i] = true;

        else if(i-x >=0 && !dp[i-x])
            dp[i] = true;

        else if(i-y >=0 && !dp[i-y])
            dp[i] = true;

        else
            dp[i] = false;
    }

    return dp[n];
}
int main()
{
    int x = 1, y = 4, n = 20;
    if (findWinner(n, x, y))
        cout << 'A';
    else
        cout << 'B';

    return 0;
}
