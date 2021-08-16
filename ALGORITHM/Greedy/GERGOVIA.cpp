#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

int work(int arr[],int n)
{
    vector<pi> buy,sell;

    for(int i=0;i<n;i++)
    {
        if(arr[i] > 0)
            buy.push_back({arr[i],i});

        else if(arr[i] < 0)
            sell.push_back({abs(arr[i]),i});
    }

    int i=0,j = 0,w = 0;

    while(i < buy.size() && j < sell.size())
    {
        int bottles = min(buy[i].first,sell[j].first);

        buy[i].first -= bottles;
        sell[j].first -= bottles;

        w += bottles * abs(buy[i].second-sell[j].second);

        if(buy[i].first == 0)
            i++;

        if(sell[j].first == 0)
            j++;
    }

    return w;
}

int main()
{
    int arr[] = {5 ,-4 ,1 ,-3 ,1};

    int n = sizeof(arr)/sizeof(int);

    cout<<work(arr,n);
}
