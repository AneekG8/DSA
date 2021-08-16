#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pi;

typedef pair<int,pair<int,int>> ppi;

void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void printArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

bool comp(ppi p1,ppi p2)
{
    if(p1.second.first==p2.second.first)
        return p1.second.second<p2.second.second;

    else
        return p1.second.first>p2.second.first;

}

void sortByFreq(int arr[],int n)
{
    unordered_map<int,pi> freq;

    for(int i=0;i<n;i++)
    {
        if(freq.find(arr[i])==freq.end())
            freq[arr[i]]={1,i};
        else
            freq[arr[i]].first++;
    }

    //store them in vector
    vector<ppi> v;
    for(auto it=freq.begin();it!=freq.end();it++)
        v.push_back({it->first,{it->second.first,it->second.second}});

    sort(v.begin(),v.end(),comp);

    for(int i=0,j=0;i<v.size();i++)
    {
        while(v[i].second.first)
            arr[j]=v[i].first,j++,v[i].second.first--;
    }
}

void sortByFreq2(int arr[],int n)
{
    vector<pi> ind;

    for(int i=0;i<n;i++)
        ind.push_back({arr[i],i});

    sort(ind.begin(),ind.end());

    vector<ppi> v;

    //nt vi=-1;

    for(int i=0;i<n;i++)
    {
        int vi=v.size()-1;

        if(vi<0 || v[vi].first!=ind[i].first)
            v.push_back({ind[i].first,{1,ind[i].second}});

        else
            v[vi].second.first++;//,v[vi].second.second=min(v[vi].second.second,ind[i].second);
    }

    sort(v.begin(),v.end(),comp);

    for(int i=0,j=0;i<v.size();i++)
    {
        while(v[i].second.first)
            arr[j]=v[i].first,j++,v[i].second.first--;
    }
}



/*/using BST || STL MAP

bool comp1(pi p1,pi p2)
{
    if(p1.first==p2.first)
        return p1.second<p2.second;

    return p1.first<p2.first;

}


void sortByFreq3(int arr[],int n)
{
    vector<pi> v;

    for(int i=0;i<n;i++)
        v.push_back(arr[i],i);

    sort(v.begin(),v.end(),comp1);

    set<ppi> s;

    for(int i=0;i<n;i++)
    {
        if(s.find(v[i].first)!=s.end())
            s.insert({v[i].first,{1,v[i].second}});

        else
            m[v[i]].first++;
    }
}
*/

int main()
{
    int arr[] = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sortByFreq2(arr, n);

    printArray(arr,n);

    return 0;
}
