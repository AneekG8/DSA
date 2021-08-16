//find the first element in the array which repeats(lowest indexed element with frequency more than 1)

#include<bits/stdc++.h>
using namespace std;


//1)brute force

//2)sorting a duplicate array then binary search for each element in original array in the duplicate array and check for adjacent elements


//3)HASHING
int firstRepeating(int arr[],int n)
{
    int min_ind = INT_MAX;

    unordered_map<int,int> s;

    for(int i=0;i<n;i++)
    {
        auto it = s.find(arr[i]);

        if(it == s.end())
            s.insert({arr[i],i});

        else
            min_ind = min(min_ind,it->second);
    }

    return min_ind == INT_MAX ? -1 : min_ind;
}

int main()
{

    int arr[] = {10, 5, 3, 4, 1};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<firstRepeating(arr, n);
}
