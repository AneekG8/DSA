#include<bits/stdc++.h>
using namespace std;

int getCount(int n)
{
    int dp[2][10];

    //memset(dp[0],1,sizeof(dp));

    for(int i=0;i<10;i++)
        dp[0][i] = 0,dp[1][i] = 1;

    for(int i=2;i<=n;i++)
    {

        //valid moves
        dp[i%2][0] = dp[(i+1)%2][8] + dp[(i+1)%2][0];
        dp[i%2][1] = dp[(i+1)%2][2] + dp[(i+1)%2][4] + dp[(i+1)%2][1];
        dp[i%2][2] = dp[(i+1)%2][1] + dp[(i+1)%2][3] + dp[(i+1)%2][5] + dp[(i+1)%2][2];
        dp[i%2][3] = dp[(i+1)%2][2] + dp[(i+1)%2][6] + dp[(i+1)%2][3];
        dp[i%2][4] = dp[(i+1)%2][1] + dp[(i+1)%2][5] + dp[(i+1)%2][7] + dp[(i+1)%2][4];
        dp[i%2][5] = dp[(i+1)%2][2] + dp[(i+1)%2][4] + dp[(i+1)%2][6] + dp[(i+1)%2][8] + dp[(i+1)%2][5];
        dp[i%2][6] = dp[(i+1)%2][3] + dp[(i+1)%2][5] + dp[(i+1)%2][9] + dp[(i+1)%2][6];
        dp[i%2][7] = dp[(i+1)%2][4] + dp[(i+1)%2][8] + dp[(i+1)%2][7];
        dp[i%2][8] = dp[(i+1)%2][5] + dp[(i+1)%2][7] + dp[(i+1)%2][0] + dp[(i+1)%2][9] + dp[(i+1)%2][8];
        dp[i%2][9] = dp[(i+1)%2][6] + dp[(i+1)%2][8] + dp[(i+1)%2][9];
    }

    int sum = 0;

    for(int i=0;i<=9;i++)
        sum += dp[n%2][i];

    return sum;
}


int main()
{
    cout<<getCount(2);
}
