#include<bits/stdc++.h>
using namespace std;

int arraySum(int arr[],int i,int j)
{
    int sum = 0;

    for(int x=i;x<=j;x++)
        sum += arr[x];

    return sum;
}


int optimalCost(int freq[],int i,int j)
{
    if(j < i)
        return 0;

    if(i == j)
        return freq[i];

    int cost = INT_MAX;

    for(int r=i;r<=j;r++)
        cost = min(cost,arraySum(freq,i,j) + optimalCost(freq,i,r-1) + optimalCost(freq,r+1,j));

    return cost;
}

int optimalCostDP(int freq[],int n)
{
    /* Create an auxiliary 2D matrix to store results
    of subproblems */
    int cost[n][n];

    /* cost[i][j] = Optimal cost of binary search tree
    that can be formed from keys[i] to keys[j].
    cost[0][n-1] will store the resultant cost */

    // For a single key, cost is equal to frequency of the key
    for (int i = 0; i < n; i++)
        cost[i][i] = freq[i];

    // Now we need to consider chains of length 2, 3, ... .
    // L is chain length.
    for (int L = 2; L <= n; L++)
    {
        // i is row number in cost[][]
        for (int i = 0; i <= n-L+1; i++)
        {
            // Get column number j from row number i and
            // chain length L
            int j = i+L-1;
            cost[i][j] = INT_MAX;

            // Try making all keys in interval keys[i..j] as root
            for (int r = i; r <= j; r++)
            {
            // c = cost when keys[r] becomes root of this subtree
            int c = ((r > i)? cost[i][r-1]:0) +
                    ((r < j)? cost[r+1][j]:0) +
                    arraySum(freq, i, j);
            if (c < cost[i][j])
                cost[i][j] = c;
            }
        }
    }
    return cost[0][n-1];
}

int optimalSearchTree(int keys[],int freq[],int n)
{
    return optimalCostDP(freq,n);
}

int main()
{

    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n = sizeof(keys) / sizeof(keys[0]);
    cout << "Cost of Optimal BST is "<< optimalSearchTree(keys, freq, n);
    return 0;

}
