#include<bits/stdc++.h>

using namespace std;

int maxPairSum(int arr[],int n,int k)
{
    //sort
    sort(arr,arr+n);

    int dp[n];

    dp[0] = 0;  //sum = 0 for no pairs

    for(int i=1;i<n;i++)
    {
        dp[i] = dp[i-1];

        //if pairing is possible
        if(arr[i]-arr[i-1] < k)
        {
            //either pair with previous element or don't pair
            if(i >= 2 )
                dp[i] = max(dp[i],dp[i-2]+arr[i]+arr[i-1]);

            else
                dp[i] = max(dp[i],arr[i]+arr[i-1]);
        }
    }

    return dp[n-1];
}

int maxPairSum2(int arr[],int n,int k)
{
    sort(arr,arr+n);

    int maxSum = 0;

    for(int i=n-1;i>0;i--)
    {
        if(arr[i]-arr[i-1] < k)
        {
            maxSum += arr[i]+arr[i-1];

            i--;
        }
    }

    return maxSum;
}


int main()
{
    int arr[] = { 3, 5, 10, 15, 17, 12, 9 };
    int N = sizeof(arr) / sizeof(int);

    int K = 4;
    cout << maxPairSum2(arr, N, K);
    return 0;
}
