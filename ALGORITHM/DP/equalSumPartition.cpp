#include<bits/stdc++.h>

using namespace std;

bool hasEqualSumPartition(int arr[],int n)
{
    //we have to find a subset with arraySum/2 (if arraySum is even)
    int sum = 0;

    for(int i=0;i<n;i++)
        sum += arr[i];

    if(sum % 2 != 0)    return false;

    bool dp[sum/2+1][n+1];

    for(int i=0;i<sum/2+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            if(i == 0)
                dp[i][j] = true;

            else if(j == 0)
                dp[i][j] = false;

            else
            {
                //value > sum
                if(arr[j-1] > i)
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = dp[i-arr[j-1]][j-1] || dp[i][j-1];
            }
        }
    }

    return dp[sum/2][n];
}

int main()
{
    int arr[] = { 1, 5, 3 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    if (hasEqualSumPartition(arr, n) == true)
        cout << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";
    return 0;
}
