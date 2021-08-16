/*
Given an array of integers and a number k,
write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
*/

#include<bits/stdc++.h>
using namespace std;

//!approach

//we take a hash map and store frequencies of remainders from given array (arr[i]%k)

//now we traverse the map and take a remainder
//for each remainder cases those arise are

//if remainder is 0 then number of such remainders must be even (for making pairs because they make pairs with themselves only)

//if remainder parts k in two equal halves frequency of such must be even

//else frequency of a remainder must be equal to the frequency of k-remainder

bool divideInPairs(int arr[],int n,int k)
{
    if(n%2!=0)
        return false;

    unordered_map<int,int> freq;

    for(int i=0;i<n;i++)
        freq[arr[i]%k]++;

    for(int i=0;i<n;i++)
    {
        int r=arr[i]%k;

        if(r==0)
            {if(freq[r] & 1) return false;}   //odd

        else if(2*r==k)
            {if(freq[r] & 1) return false;}

        else if(freq[r]!=freq[k-r]) return false;
    }

    return true;
}

int main()
{
    int arr[] =  {91,74,66,49,55,20,65,60};
    int k = 10;
    int n = sizeof(arr)/sizeof(arr[0]);
    divideInPairs(arr, n, k)? cout << "True": cout << "False";
    return 0;
}
