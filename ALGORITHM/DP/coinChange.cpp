/*
Given a value N, if we want to make change for N cents, and we have
infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
how many ways can we make the change? The order of coins doesn’t matter.
*/

#include<iostream>

using namespace std;

/*
To count the total number of solutions, we can divide all set solutions into two sets.
1) Solutions that do not contain mth coin (or Sm).
2) Solutions that contain at least one Sm.
Let count(S[], m, n) be the function to count the number of solutions,
then it can be written as sum of count(S[], m-1, n) and count(S[], m, n-Sm).
*/


//recursive soln
int countRecur(int s[],int m,int n)
{
    if(n==0)
        return 1;

    if(n<0)
        return 0;

    if(m<=0 && n>0)
        return 0;

    return countRecur(s,m,n-s[m-1]) + countRecur(s,m-1,n);
}


//DP solution : O(mn) space
int countDP(int s[],int m,int n)
{
    int table[n+1][m];

    for(int i=0;i<m;i++)
        table[0][i]=1;  //base value case when n=0

    //fill in bottom-up manner
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            //include at least one s[j]
            int x = (i-s[j]) >= 0 ? table[i-s[j]][j] : 0;

            //excluding s[j]
            int y = (j >= 1) ? table[i][j-1] : 0;

            table[i][j] = x+y;
        }
    }

    return table[n][m-1];
}


//DP solution : O(n) space

//use formula if amount >= coin  count(amount) += count(amount-coin)


int main()
{
    int arr[] = {1, 2, 5};
    int m = sizeof(arr)/sizeof(arr[0]);
    cout<<countDP(arr, m, 12);
    return 0;
}

