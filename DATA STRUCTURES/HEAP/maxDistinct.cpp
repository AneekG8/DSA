/*
Given an array arr[] containing n elements.
The problem is to find maximum number of distinct elements (non-repeating) after removing k elements from the array.
you are allowed to remove any k elements.
*/

#include<bits/stdc++.h>
using namespace std;

//1<=k<=n
int maxDistinct(int arr[],int n,int k)
{
    unordered_map<int,int> count;

    for(int i=0;i<n;i++)
    {
        if(count.find(arr[i])==count.end())
            count[arr[i]]=1;
        else
            count[arr[i]]++;
    }

    int d=0;

    priority_queue<int,vector<int>,greater<int>> pq;

    for(auto itr=count.begin();itr!=count.end();itr++)
    {
        if(itr->second==1)
            d++;
        else
            pq.push(itr->second-1);
    }

    while(!pq.empty() && k>0)
    {
        int x=pq.top();
        pq.pop();

        k=k-x;

        if(k>=0)
            d++;
    }

    if(k>0)
        d=d-k;

    return d;
}

int main()
{
    int arr[] = { 18,15,14,14,14,20,1,10,12,13,17,17,17,2,3,3,5,7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 1;
    cout << "Maximum distinct elements = "
         << maxDistinct(arr, n, k);
    return 0;
}
