// https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

#include<bits/stdc++.h>
using namespace std;


int minPlatformsBrute(int arr[],int dep[],int n)
{
    int curr_p , res = INT_MIN;

    for(int i=0;i<n;i++)
    {
        curr_p = 1;
        for(int j=i+1;j<n;j++)
        {
            //find the overlaps
            if(!(arr[j]>=dep[i] || dep[j]<=arr[i]))
                curr_p++;
        }

        res = max(res,curr_p);
    }

    return res;
}

//O(nlogn)
int minPlatformsBetter(int arr[],int dep[],int n)
{
    vector<pair<int,int>> v;

    for(int i=0;i<n;i++)
        v.push_back({arr[i],dep[i]});
        
    sort(v.begin(),v.end());
    
    priority_queue<int,vector<int>,greater<int>> pq;
    
    pq.push(v[0].second);
    
    int p = 1;
    
    for(int i=1;i<n;i++)
    {
        int earliestDep = pq.top();
        
        if(v[i].first > earliestDep)
            pq.pop();
            
        pq.push(v[i].second);
        
        p = max(p,(int)pq.size());
    }
    
    return p;	
    
}


//o(n)
int minPlatformsOptimal(int arr[],int dep[],int n)
{
    int p = 0,res = INT_MIN;

    sort(arr,arr+n);
    sort(dep,dep+n);

    int i=0,j=0;

    while(i<n && j<n)
    {
        if(arr[i] <= dep[j])
        {
            p++;
            i++;
        }

        else if(arr[i] > dep[j])
        {
            p--;
            j++;
        }

        res = max(p,res);   //after each arrival or departure
    }

    return res;
}

int main()
{
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << minPlatformsBetter(arr, dep, n);
    return 0;
}
