//find 4 elements from an array a,b,c,d such that a+b = c+d (all distinct)

#include<bits/stdc++.h>
using namespace std;

//!brute force O(n^4)


//!using hashing we can map sum to the corresponding pairs

//if array contains duplicates try deleting them

typedef pair<int,int> pi;

//print utility function to print vectors of pairs
void printPairs(int sum,vector<pi> v)
{
    for(int i=0;i<v.size()-1;i++)
    {
        for(int j=i+1;j<v.size();j++)
        {
            cout<<sum<<"="<<v[i].first<<"+"<<v[i].second<<"="<<v[j].first<<"+"<<v[j].second<<endl<<endl;
        }
    }
}

void findQuadruples(int arr[],int n)
{
    bool found=false;
    unordered_map<int,vector<pi>> m;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int sum=arr[i]+arr[j];

            if(m.find(sum)!=m.end())
                found=true;

            m[sum].push_back({arr[i],arr[j]});
        }
    }

    if(!found)
        cout<<"none found"<<endl;
    else
    {
        for(auto it=m.begin();it!=m.end();it++)
        {
            printPairs(it->first,it->second);
        }
    }
}

int main()
{
    int arr[] = {3, 4, 7, 1, 2, 9, 8};
    int n  =  sizeof arr / sizeof arr[0];
    findQuadruples(arr, n);
    return 0;
}
