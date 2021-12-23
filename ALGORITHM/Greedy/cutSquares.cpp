//cut squares from a m x n board with minimum cost

// https://www.geeksforgeeks.org/minimum-cost-cut-board-squares/

#include<bits/stdc++.h>
using namespace std;


int minCost(int vert[],int hrz[],int m,int n)   //vertical costs,horizontal costs,vertical lines,horizontal lines
{
    
    sort(vert,vert+m,greater<int>());

    sort(hrz,hrz+n,greater<int>());

    int hp = 1, vp = 1;     //initial pieces

    int vi = 0, hi = 0;     //vertical index,horizontal index

    int cost = 0;

    while(vi < m && hi < n)
    {
        if(hrz[hi] > vert[vi])
        {
            cost += hrz[hi] * vp;
            hp++;
            hi++;
        }

        else
        {
            cost += vert[vi] * hp;
            vp++;
            vi++;
        }
    }

    //after one array ends
    while(vi<m)
    {
        cost += vert[vi] * hp;
        vi++;
    }

    while(hi<n)
    {
        cost += hrz[hi] * vp;
        hi++;
    }

    return cost;
}
int main()
{
    int m = 6, n = 4;
    int X[m-1] = {2, 1, 3, 1, 4};   //vertical costs
    int Y[n-1] = {4, 1, 2};     //horizontal costs
    cout << minCost(X, Y, m-1, n-1);
    return 0;
}
