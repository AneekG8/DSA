#include<bits/stdc++.h>
using namespace std;

typedef pair<int,pair<int,int>> pii;

class compare{

public:
    bool operator()(pii a,pii b)    //val,index,count
    {
       if(a.second.second == b.second.second)
            return a.second.first > b.second.first;

       return a.second.second < b.second.second ;
    }
};

//O(klogd + d)  //d being number of distinct elements
void kMostFrequent(int arr[],int n,int k)
{
    unordered_map<int,pair<int,int>> count;

    for(int i=0;i<n;i++)
    {
        if(count.find(arr[i]) == count.end())
            count.insert({arr[i],{i,1}});

        else
            count[arr[i]].second++;
    }

    priority_queue<pii,vector<pii>,compare> pq(count.begin(),count.end());

    for(int i=0;i<k;i++)
    {
        cout<<pq.top().first<<" ";
        pq.pop();
    }
}

//another approach could have been
//using hash map store count of distinct elements(d)
//store pairs of count and element in a vector
//then use custom comparator and sort the vector


int main()
{
    int arr[] = {7, 10, 11, 5, 2, 5, 7, 11, 8, 9,10,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    kMostFrequent(arr, n, k);
    return 0;
}
