#include<bits/stdc++.h>

using namespace std;

int dp[100][100];


//DP : Tabulation method
int minCostMCM(int* d,int n)
{
    int c[n][n];

    for(int i=0;i<n;i++)
        c[i][i] = 0;

    for(int p=1;p<n-1;p++)
    {
        for(int i=1;i+p<n;i++)
        {
            int j = i+p; //such that j-i = p

            c[i][j] = INT_MAX;

            for(int k=i;k<j;k++)
                c[i][j] = min( c[i][j], (c[i][k]+c[k+1][j]+d[i-1]*d[k]*d[j]) );
        }
    }

    return c[1][n-1];
}


//DP: Memorization method

int minCostMCMRecurMem(int* d,int i,int j)
{
    if(i==j) return 0;

    if(dp[i][j] != -1)  return dp[i][j];

    int cost = INT_MAX;

    for(int k=i;k<j;k++)
        cost = min(cost,minCostMCMRecurMem(d,i,k)+minCostMCMRecurMem(d,k+1,j)+d[i-1]*d[k]*d[j]);

    return dp[i][j] = cost;
}

int minCostMCMRecur(int* d,int n)
{
    memset(dp,-1,sizeof(dp));

    return minCostMCMRecurMem(d,1,n-1);
}

int main()
{
    int arr[] = {40, 20, 30,10,30};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is "
         << minCostMCMRecur(arr,size);

    return 0;
}
