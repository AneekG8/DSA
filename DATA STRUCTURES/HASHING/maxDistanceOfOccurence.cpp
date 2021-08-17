//given an array with repeating elements find the maximum distance between two occurrences of an element

// https://practice.geeksforgeeks.org/problems/max-distance-between-same-elements/1 (checkout the solution)

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

int maxDistanceOfOccuurence(int arr[],int n)
{
    unordered_map<int,pi> m;    //pi stores first occurrence and max distance up till now respectively

    for(int i=0;i<n;i++)
    {
        if(m.find(arr[i])==m.end())
            m[arr[i]]={i,0};

        else
            m[arr[i]]={m[arr[i]].first,i-m[arr[i]].first};
    }

    int max_dist=0;

    for(auto itr=m.begin();itr!=m.end();itr++)
        if((itr->second).second > max_dist) max_dist=(itr->second).second;

    return max_dist;
}

int main()
{
    int arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxDistanceOfOccuurence(arr, n);
    return 0;
}
