//find the kTh smallest in a n x n  matrix

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> ppi;

int kThSmallest(int arr[4][4],int n,int k)
{
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;

    for(int i=0;i<n;i++)
        pq.push({arr[i][0],{i,0}});

    ppi curr_min;

    for(int i=0;i<k;i++)
    {
        curr_min=pq.top();
        pq.pop();

        int curr_row=curr_min.second.first;
        int curr_col=curr_min.second.second;

        if(curr_col==n-1)
            pq.push({INT_MAX,{curr_row,curr_col+1}});   //after we have reached last col of a row
        else
            pq.push({arr[curr_row][curr_col+1],{curr_row,curr_col+1}});
    }

    return curr_min.first;
}


int main()
{
    int mat[4][4] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {25, 29, 37, 48},
                    {32, 33, 39, 50},
                };
    cout << "7th smallest element is " << kThSmallest(mat, 4, 16);
    return 0;
}
