#include<bits/stdc++.h>

using namespace std;

int knapsackRecur(int w,int wt[],int v[],int n)
{
    if(n==0 || w==0)
        return 0;

    if(wt[n-1]>w)
        return knapsackRecur(w,wt,v,n-1);

    return max(  ( v[n-1] + knapsackRecur(w-wt[n-1],wt,v,n-1) )  ,  knapsackRecur(w,wt,v,n-1) );
}


//DP solution
int knapsackDP(int w,int wt[],int v[],int n)
{
    int arr[w+1][n+1];

    for(int i=0;i<=w;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                arr[i][j]=0;

            else if(i>=wt[j-1])
                arr[i][j]= max( (v[j-1]+arr[i-wt[j-1]][j-1]) , arr[i][j-1]);

            else
                arr[i][j]=arr[i][j-1];
        }
    }

    return arr[w][n];
}


int main()
{
    int val[] = { 60, 100, 120 , 200};
    int wt[] = { 10, 20, 30 , 35};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsackDP(W, wt, val, n);
    return 0;
}
