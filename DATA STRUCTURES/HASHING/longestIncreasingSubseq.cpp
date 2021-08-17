//Given N elements
//write a program that prints the length of the longest increasing subsequence whose adjacent element difference is one.

// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/submissions/

#include<bits/stdc++.h>
using namespace std;

//!we can use brute force which takes O(n^2) time
//for each element check for the required subsequence length and update max length



//!Efficient method is to use dynamic programming

//we create a dp[n] array where dp[i] stores the length of subsequence ending with arr[i]

//so the relation becomes :- if arr[i]-1 exists before arr[i] then length increases by 1

int longestIncreasingSubseqLength(int arr[],int n)
{
    unordered_map<int,int> index;   //maps each value with its index

    int dp[n];

    int max_len=INT_MIN;

    for(int i=0;i<n;i++)
    {
        //if arr[i]-1 appears before arr[i]
        if(index.find(arr[i]-1) != index.end())
        {
            dp[i] = 1 + dp[ index[ arr[i]-1 ] ];    //because arr[i] comes after arr[i]-1
        }
        else
            dp[i]=1;

        index[arr[i]]=i;

        if(max_len<dp[i])
            max_len=dp[i];
    }

    return max_len;
}



//!now what if we are asked to find the subsequence

//so we have got the length of the subsequence now we need either first or last element of the sequence

//we can easily find the last element

//if dp[i]==max_len we know that arr[i] will be the last element

void longestIncreasingSubseq(int arr[],int n)
{
    unordered_map<int,int> index;   //maps each value with its index

    int dp[n];

    int max_len=INT_MIN;

    int first,last;

    for(int i=0;i<n;i++)
    {
        //if arr[i]-1 appears before arr[i]
        if(index.find(arr[i]-1) != index.end())
        {
            dp[i] = 1 + dp[ index[ arr[i]-1 ] ];    //because arr[i] comes after arr[i]-1
        }
        else
            dp[i]=1;

        index[arr[i]]=i;

        if(max_len<dp[i])
        {
            max_len=dp[i];

            last=arr[i];

            first=arr[i]-max_len+1; //first element of the sequence as arr[i] is the last element
        }
    }

    //print the sequence
    for(int i=first;i<=last;i++)
        cout<<i<<" ";

}



int main()
{
    int a[] = {3,10,3,11,4,5,6,7,8,12};
    int n = sizeof(a) / sizeof(a[0]);
    cout << longestIncreasingSubseqLength(a, n)<<endl;
    longestIncreasingSubseq(a,n);
    return 0;
}
