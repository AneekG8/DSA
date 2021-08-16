#include<bits/stdc++.h>

using namespace std;

int lcsDP(int n,int m,int a[],int b[])
{
    int dp[n+1][m+1];

        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 || j == 0)
                    dp[i][j] = 0;

                else if(a[i-1] == b[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];

                else
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }

        return dp[n][m];
}


int lcs(int n,int m,int a[],int b[])
{
    if(n == 0 || m == 0)
        return 0;
    if(a[n-1] == b[m-1])
        return 1+lcs(n-1,m-1,a,b);
    else
        return max( lcs(n,m-1,a,b),lcs(n-1,m,a,b) );
}

int lis(int arr[],int n)
{
    int lis[n];

    lis[0] = 1;

    for(int i=1;i<n;i++)
    {
        lis[i] = 1;

        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
                lis[i] = max(lis[i],lis[j]+1);
        }
    }

    return *max_element(lis,lis+n);
}

int _lis(int arr[],int n)
{
    set<int> s;

    for(int i=0;i<n;i++)
        s.insert(arr[i]);

    int m = s.size();

    int b[m];

    int i=0;

    for(auto it = s.begin();it != s.end();it++,i++)
        b[i] = *it;

    for(int i=0;i<m;i++)
        cout<<b[i]<<endl;

    return lcsDP(n,m,arr,b);
}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Length of lis is %d\n", _lis(arr, n));

    return 0;
}
