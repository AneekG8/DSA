//given an array of 0s and 1s only find number of sub arrays containing equal numbers of 0s and 1s
//https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1#

#include<bits/stdc++.h>
using namespace std;


//!approach brute force O(n^2)



//!approach hashing

//the trick is to use 0s as -1s

//so now we have an array of -1s and 1s....so any sub array with equal 0s(-1s) and 1s will have array sum of 0

//we store frequency of cumulative sums in a hash map

//for cumulative sum 0 a desired sub array ends at that index starting from index 0

//for a sum already seen we were only taken account for the first occurrence for the sake of the largest sub array

//!because each time a sum is seen a desired sub array starts after that index so a combination of all the freq[sum] is needed
//this is applied in case of sum=0 also (a sub array between to 0 as cumulative sum)

int countSubarray(int arr[],int n)
{
    unordered_map<int,int> freq;

    int sum=0;

    int count=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i])
            sum+=arr[i];
        else
            sum+=-1;    //in case of 0s

        freq[sum]++;
    }

    for(auto it=freq.begin();it!=freq.end();it++)
    {
        int sum=it->first;

        if(sum==0)
            count+=freq[sum];

        if(freq[sum]>1)    //sum must have been seen before
            count+=(freq[sum] * (freq[sum]-1))/2;  //combinations of all starting and ending index
    }

    return count;
}

int main()
{
    int arr[] = { 1,0,0,1,0,1,1};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout<<countSubarray(arr, size);
    return 0;
}

