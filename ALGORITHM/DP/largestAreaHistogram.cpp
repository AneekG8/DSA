//find the largest area possible from a histogram

#include<bits/stdc++.h>
using namespace std;

int maxArea(int arr[],int n)
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

        maxArea = max(area,maxArea);
    }

    return maxArea;
}

int main()
{
    int hist[] = {2,3,3,2};
    int n = sizeof(hist)/sizeof(hist[0]);
      cout << "maxArea = " << maxArea(hist, n) << endl;
    return 0;
}
