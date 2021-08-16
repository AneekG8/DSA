//given an array find number of pairs(a,b) such that a XOR b=0

#include<bits/stdc++.h>
using namespace std;


//!approach

//aXORb=0 if a=b
//so the solution is based on counting freq || for freq c ans= nC2

//which can be done in O(nlogn) with sorting

//or O(n) with hashing(assumed)

//we can use index mapping with a freq array(freq[a[i]]) if the array has small numbers

int countPairs(int arr[],int n)
{
    unordered_map<int,int> count;

    for(int i=0;i<n;i++)
        count[arr[i]]++;

    int pairs=0;

    for(auto it=count.begin();it!=count.end();it++)
            pairs+=( (it->second) * (it->second-1) ) / 2;   //nC2

    return pairs;
}

int main()
{
    int a[] = {1, 2, 1, 2, 4};
   int n = sizeof(a) / sizeof(a[0]);

   // Function calling
   cout << (countPairs(a,n));
}
