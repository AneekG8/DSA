#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> arr,int k)
{
    int n = arr.size();

    int dp[k+1][n+1];

    memset(dp,0,sizeof(dp));

    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j] = dp[i][j-1];

            if(arr[j-1] <= i)
                dp[i][j] += dp[i/arr[j-1]][j-1] + 1;
        }
    }

    return dp[k][n];
}

int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int k = 10;
    cout << solution(A, k) << endl;
}
