#include<bits/stdc++.h>
using namespace std;

int maxAreaHist(int arr[],int n,int* height,int* left,int* right)
{
    //we will use each value as height and boundary of width will be NSE and PSE of the current bar

    int lb[n],rb[n];    //store boundaries of each bar

    stack<int> s;

    //find right bouhndaries
    rb[n-1] = n, s.push(n-1);

    for(int i=n-2;i>=0;i--)
    {
        while(!s.empty() && arr[i] <= arr[s.top()])
            s.pop();

        rb[i] = s.empty() ? -1 : s.top();

        s.push(i);
    }

    while(!s.empty())
        s.pop();

    //find left boundaries
    lb[0] = -1, s.push(0);

    for(int i=1;i<n;i++)
    {
        while(!s.empty() && arr[i] <= arr[s.top()])
            s.pop();

        lb[i] = s.empty() ? -1 : s.top();

        s.push(i);
    }

    //find the maxArea possible
    int maxArea = INT_MIN;

    for(int i=0;i<n;i++)
    {
        int area = arr[i] * (rb[i]-lb[i]-1);

        if(maxArea < area)
        {
            maxArea = area;
            *height = arr[i];
            *right = rb[i]-1;
            *left = lb[i]+1;
        }
    }

    return maxArea;
}

int maxAreaHist(vector<int> v,int* height,int* left,int* right)
{
    int arr[v.size()];

    for(int i=0;i<v.size();i++)
        arr[i] = v[i];

    return maxAreaHist(arr,v.size(),height,left,right);
}

void maxAreaRect(vector<vector<int>> m)
{
    vector<vector<int>> original(m);

    int rows = m.size();
    int cols = m[0].size();

    int maxArea,maxUp,maxDown,maxLeft,maxRight;

    int height,left,right;

    maxArea = maxAreaHist(m[0],&height,&left,&right); //from first row

    maxUp = 0-height+1,maxDown = 0,maxLeft = left,maxRight = right;

    for(int i=1;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(m[i][j])
                m[i][j] += m[i-1][j];
        }

        int area = maxAreaHist(m[i],&height,&left,&right);

        if(maxArea < area)
        {
            maxArea = area;
            maxUp = i-height+1;
            maxDown = i;
            maxLeft = left;
            maxRight = right;
        }
    }

    cout<<"Max Area is: "<<maxArea<<endl;

    for(int i=maxUp;i<=maxDown;i++)
    {
        for(int j=maxLeft;j<=maxRight;j++)
        {
            cout<<original[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<int>> m = {
        { 0, 1, 1},
        { 1, 1, 1},
        { 0, 1, 1},
    };

    maxAreaRect(m);

    return 0;
}

