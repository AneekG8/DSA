//cut squares from a m x n board with minimum cost

#include<bits/stdc++.h>
using namespace std;


int minCost(int hrz[],int vert[],int m,int n)
{
    sort(hrz,hrz+m,greater<int>());

    sort(vert,vert+n,greater<int>());

    int hp = 1, vp = 1; //initial pieces

    int i = 0, j = 0;

    int cost = 0;

    while(i < m && j < n)
    {
        if(hrz[i] > vert[j])
        {
            cost += hrz[i] * hp;
            vp++;
            i++;
        }

        else
        {
            cost += vert[j] * vp;
            hp++;
            j++;
        }
    }

    //after one array ends
    while(i<m)
    {
        cost += hrz[i] * hp;
        i++;
    }

    while(j<n)
    {
        cost += vert[j] * vp;
        j++;
    }

    return cost;
}
int main()
{
    int m = 6, n = 4;
    int X[m-1] = {2, 1, 3, 1, 4};
    int Y[n-1] = {4, 1, 2};
    cout << minCost(X, Y, m-1, n-1);
    return 0;
}
