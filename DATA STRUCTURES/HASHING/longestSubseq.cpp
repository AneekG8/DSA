//Given N elements
//write a program that prints the length of the longest subsequence whose adjacent element difference is one.
//!the sequence might be increasing or decreasing or both(duplicates allowed)

#include<bits/stdc++.h>
using namespace std;


//!approach
// create a hash map and map element with the length of the sequence ending with that element

int longestSubseqLength(int arr[],int n)
{
    unordered_map<int,int> m;

    for(int i=0;i<n;i++)
    {
        int len=0;

        if(m.find(arr[i]-1)!= m.end())
            len=max(len,m[arr[i]-1]);

        if(m.find(arr[i]+1)!= m.end())
            len=max(len,m[arr[i]+1]);

        m[arr[i]]=1+len;
    }

    int max_len=INT_MIN;

    for(auto it=m.begin();it!=m.end();it++)
        max_len=max(max_len,it->second);

    return max_len;
}

int main()
{
    int arr[] = {1,2,3,4,5,3,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Longest length subsequence = "
         << longestSubseqLength(arr, n);
    return 0;
}
