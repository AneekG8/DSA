//given a sequence  find the largest derangement possible

#include<bits/stdc++.h>
using namespace std;

vector<int> largestDerangement(int arr[],int n)
{
    vector<int> v;

    //use max-heap
    priority_queue<int> pq(arr,arr+n);

    for(int i=0;i<n;i++)
    {
        int x=pq.top();
        pq.pop();

        if(x!=arr[i] || i==n-1) //for the last element we have to push the only element from heap
            v.push_back(x);
        else
        {
            v.push_back(pq.top());
            pq.pop();

            pq.push(x);
        }
    }

    //check for last element
        if(v[n-1]==arr[n-1])
        {
            //swap with preceding element
            v[n-1]=v[n-2];
            v[n-2]=arr[n-1];
        }

    return v;
}

int main()
{
    int seq[] = {56,21,42,67,23,1};
    int n = sizeof(seq)/sizeof(seq[0]);

    vector<int> v=largestDerangement(seq,n);

    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

    return 0;
}
