//find the kTh largest elements from a given stream of integers

#include<bits/stdc++.h>
using namespace std;

void kThLargestStream(int arr[],int n,int k)
{
    //make a min heap of k elements
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<k-1;i++)
        cout<<"-1 ",pq.push(arr[i]);

    //for kTh element
    pq.push(arr[k-1]);
    cout<<pq.top()<<" ";

    for(int i=k;i<n;i++)
    {
        if(arr[i]>pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
        cout<<pq.top()<<" ";
    }
}

int main()
{
    int arr[]={10,20,11,70,50,40,100,5};

    int n=sizeof(arr)/sizeof(int);

    int k=3;

    kThLargestStream(arr,n,k);

    return 0;
}
