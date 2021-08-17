//given an array find out the smallest sub array containing all the occurrences of the most frequent element

// https://practice.geeksforgeeks.org/problems/smallest-subarray-with-all-occurrences-of-a-most-frequent-element2258/1

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pi;

void smallestWindow(int arr[],int n)
{
    //map for frequency
    unordered_map<int,int> freq;

    //map to store first and last index of an element
    unordered_map<int,pi> ind;

    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;

        if(ind.find(arr[i])==ind.end())
            ind[arr[i]]={i,i};

        else
            ind[arr[i]].second=i;   //last index
    }

    int max_freq=INT_MIN;

    for(auto itr=freq.begin();itr!=freq.end();itr++)
        if(itr->second > max_freq)  max_freq=itr->second;

    int min_window=INT_MAX;

    for(auto itr=ind.begin();itr!=ind.end();itr++)
    {
        int curr_window=(itr->second).second-(itr->second).first;

        if(freq[itr->first]==max_freq && curr_window<min_window)
            min_window=curr_window;
    }

    for(auto itr=ind.begin();itr!=ind.end();itr++)
    {
        int curr_window=(itr->second).second-(itr->second).first;

        if(curr_window==min_window)
        {
            int first=(itr->second).first;

            int last=(itr->second).second;

            for(int i=first;i<=last;i++)
                cout<<arr[i]<<" ";

            cout<<endl;
        }
    }
}
//prints all the smallest windows which has all occurrences of a most frequent element

int main()
{
    int A[] = { 1,7,5,1,2,3,4,2,3,4 };
    int n = sizeof(A) / sizeof(A[0]);
    smallestWindow(A, n);
    return 0;
}
