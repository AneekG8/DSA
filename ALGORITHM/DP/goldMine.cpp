/*
Given a gold mine of n*m dimensions. Each field in this mine contains a positive integer which is the amount of gold in tons.
Initially the miner is at first column but can be at any row. He can move only (right->,right up /,right down\)
that is from a given cell, the miner can move to the cell diagonally up towards the right or right or diagonally down
towards the right.

Find out maximum amount of gold he can collect.
*/

#include<bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> vvi;

int getMaxGold(vvi gold)
{
    int res=0;

    int m=gold.size();
    int n=gold[0].size();

    vvi goldTable(m,vector<int>(n,0));

    for(int col=0;col<n;col++)
    {
        for(int row=0;row<m;row++)
        {
            int leftUp = col==0 || row==0 ? 0 : goldTable[row-1][col-1];

            int left = col==0 ? 0 : goldTable[row][col-1];

            int leftDown = col==0 || row==m-1 ? 0 : goldTable[row+1][col-1];

            goldTable[row][col] = gold[row][col] + max(max(leftUp,left),leftDown);

            if(col==n-1)
                res=max(res,goldTable[row][col]);
        }
    }

    return res;
}

int main()
{
    vvi gold = {{10, 33, 13, 15},
                  {22, 21, 04, 1},
                  {5, 0, 2, 3},
                  {0, 6, 14, 2}};

    cout<<getMaxGold(gold);

    return 0;
}
