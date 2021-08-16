//maximize the profit of a stock selling with maximum k transactions allowed

#include<bits/stdc++.h>
using namespace std;

int maxProfit(int arr[],int n,int k)
{
        int dp[k+1][n];

        for(int i=0;i<=k;i++)
        {
            for(int j=0;j<n;j++)
            {
                int maxVal = INT_MIN;
                if(i == 0 || j == 0)
                    dp[i][j] = 0;   //0th day or 0 transactions

                else
                {
                    //sell on that day when we buy on m'th day
                    for(int m=0;m<j;m++)
                        maxVal = max(maxVal,(arr[j]-arr[m] + dp[i-1][m]));

                    //no transaction on that day
                    dp[i][j] = max(maxVal,dp[i][j-1]);
                }
            }
        }

        return dp[k][n-1];
}


//further optimization
int maxProfit1(int arr[],int n,int k)
{
        int dp[k+1][n];

        for(int i=0;i<=k;i++)
        {
            int maxDiff = INT_MIN;
            for(int j=0;j<n;j++)
            {

                if(i == 0 || j == 0)
                    dp[i][j] = 0;   //0th day or 0 transactions

                else
                {
                    //sell on that day when we buy on m'th day
                    maxDiff = max(maxDiff,(dp[i-1][j-1]-arr[j-1]));

                    dp[i][j] = maxDiff + arr[j];

                    //no transaction on that day
                    dp[i][j] = max(dp[i][j],dp[i][j-1]);
                }
            }
        }

        return dp[k][n-1];
}

int main()
{
    int arr[] = {20, 580, 420, 900};

    cout<<maxProfit1(arr,4,3);
}
