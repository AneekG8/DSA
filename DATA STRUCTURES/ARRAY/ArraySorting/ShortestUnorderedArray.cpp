/*
An array is given of n length, and problem is that we have to find the length of shortest unordered {neither increasing nor decreasing} sub array in given array.

The idea is based on the fact that size of shortest subarray would be either 0 or 3.
We have to check array element is either increasing or decreasing, if all array elements are in increasing or decreasing, then length of shortest sub array is 0,
And if either the array element is not follow the increasing or decreasing then it shortest length is 3.
*/
// CPP program to find shortest subarray which is 
// unsorted. 
#include <bits/stdc++.h> 
using namespace std; 
  
// bool function for checking an array elements  
// are in increasing. 
bool increasing(int a[], int n) 
{ 
    for (int i = 0; i < n - 1; i++)  
        if (a[i] >= a[i + 1]) 
            return false;     
    return true; 
} 
  
// bool function for checking an array  
// elements are in decreasing. 
bool decreasing(int a[], int n) 
{ 
    for (int i = 0; i < n - 1; i++)  
        if (a[i] < a[i + 1]) 
            return false;     
    return true; 
} 
  
int shortestUnsorted(int a[], int n) 
{ 
    // increasing and decreasing are two functions. 
    // if function return true value then print 
    // 0 otherwise 3. 
    if (increasing(a, n) == true || 
       decreasing(a, n) == true) 
        return 0; 
    else
        return 3; 
} 
  
// Driver code 
int main() 
{ 
    int ar[] = { 7, 9, 10, 8, 11 }; 
    int n = sizeof(ar) / sizeof(ar[0]); 
    cout << shortestUnsorted(ar, n); 
    return 0; 
} 
