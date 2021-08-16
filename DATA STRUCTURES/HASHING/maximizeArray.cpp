/*
Given two arrays with size n, maximize the first array by using the elements from the second array
such that the new array formed contains n greatest but unique elements of both the arrays giving the second array priority
(All elements of second array appear before first array). The order of appearance of elements is kept same in output as in input.
*/

#include<bits/stdc++.h>
using namespace std;



//!approach

//we need first n largest unique items and store them in a hash map

//we can sort 2n elements or we can use a set

//at last we traverse both arrays(2nd array first) and if a particular element exists in hash map goes into resultant array

void maximizeArray(int a[],int b[],int n)
{
    int res[n];

    set<int> s;

    //takes care of both sorting and distinction
    for(int i=0;i<n;i++)
    {
        s.insert(a[i]);
        s.insert(b[i]);
    }

    unordered_set<int> h;

    for(auto it=s.rbegin();h.size()<n;it++)
        h.insert(*it);

    int index=0;

    //traverse 2nd array
    for(int i=0;i<n && index<n;i++)
    {
        if(h.find(b[i])!=h.end())
        {
            res[index]=b[i];
            h.erase(b[i]);  //so that elements are not repeated in resultant array
            index++;
        }
    }

    //traverse 1st array
    for(int i=0;i<n && index<n;i++)     //to maintain same order as input
    {
        if(h.find(a[i])!=h.end())
        {
            res[index]=a[i];
            h.erase(a[i]);
            index++;
        }
    }

    for(int i=0;i<n;i++)
        a[i]=res[i];
}

int main()
{
    int array1[] = { 7, 4, 8, 0, 1 };
    int array2[] = { 9, 7, 2, 3, 6 };
    int size = sizeof(array1) / sizeof(array1[0]);
    maximizeArray(array1, array2, size);
    for(int i=0;i<size;i++)
        cout<<array1[i]<<" ";
    return 0;
}
