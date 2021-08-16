//given two arrays check if array 2 is subset of array 1 or not

#include<bits/stdc++.h>
using namespace std;

//!method 1

//brute force || O(n^2)

//if array 2 has duplicate elements we need to use flags
//so we create a vector<pair<int,bool>> from array 1 where bool(flag) represents availability
//for an element of array 2 if it's found in array 1 we make that element unavailable in array 1


//!method 2

//sort array 1 and binary search elements of array 2 in array 1

//O(nlogm)


//!method 3
//using hash map, this will reduce the time complexity

//to handle cases of duplicate keys we need to create a hash map with key and its count from array 1
//then search from array 2 if found decrement count by 1

bool checkSubset(int arr1[],int arr2[],int n1,int n2)
{
    unordered_map<int,int> m;

    for(int i=0;i<n1;i++)
        m[arr1[i]]++;

    for(int i=0;i<n2;i++)
    {
        if(m.find(arr2[i])==m.end() || m[arr2[i]]==0)
            return false;

        m[arr2[i]]--;
    }

    return true;
}

int main()
{
    int arr1[] = {11,1, 13, 21, 3, 7,7};
    int arr2[] = {11, 3, 7, 7, 1};

    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);

    if(checkSubset(arr1, arr2, m, n))
      printf("arr2[] is subset of arr1[] ");
    else
      printf("arr2[] is not a subset of arr1[] ");

    return 0;
}
