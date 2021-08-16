//find the largest area square sub matrix with all 1
#include<bits/stdc++.h>
using namespace std;

int maxSquare(vector<vector<int>> m)
{
    int rows = m.size();
    int cols = m[0].size();

    int dp[rows][cols],maxLen = INT_MIN;

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = m[i][j];
            else
                dp[i][j] = m[i][j] == 0 ? 0 : min(dp[i][j-1],min(dp[i-1][j-1],dp[i-1][j]))+1;

            maxLen = max(maxLen,dp[i][j]);
        }
    }

    return maxLen;

}

int main()
{
    vector<vector<int>> M = {{0, 1, 1, 0, 1},
                    {1, 1, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {1, 1, 1, 1, 0},
                    {1, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0}};

    cout <<maxSquare(M);
}
