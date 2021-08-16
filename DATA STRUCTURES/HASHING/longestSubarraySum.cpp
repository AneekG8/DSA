//given an array find length of the longest sub array with 0

#include<bits/stdc++.h>
using namespace std;


//!approach

/*
Efficient Approach: The brute force solution is calculating the sum of each and every sub-array and
checking whether the sum is zero or not. Let’s now try to improve the time complexity
by taking an extra space of ‘n’ length. The new array will store the sum of all the elements
up to that index. The sum-index pair will be stored in a hash-map.
A Hash map allows insertion and deletion of key-value pair in constant time.
Therefore, the time complexity remains unaffected. So, if the same value appears twice in the array,
it will be guaranteed that the particular array will be a zero-sum sub-array.

Mathematical Proof:
prefix(i) = arr[0] + arr[1] +…+ arr[i]
prefix(j) = arr[0] + arr[1] +…+ arr[j], j>i
if prefix(i) == prefix(j) then prefix(j) – prefix(i) = 0 that means arr[i+1] + .. + arr[j] = 0,
So a sub-array has zero sum , and the length of that sub-array is j-i

Algorithm:
Create a extra space, an array of length n (prefix), a variable (sum),
length (max_len) and a hash map (hm) to store sum-index pair as a key-value pair
Move along the input array from starting to the end
For every index update the value of sum = sum + array[i]
Check for every index, if the current sum is present in the hash map or not
If present update the value of max_len to maximum of difference of two indices
(current index and index in the hash-map) and max_len
Else Put the value (sum) in the hash map, with the index as a key-value pair.
Print the maximum length (max_len)
*/


void longestSubarrayWithZeroSum(int arr[],int n)
{
    int sum=0;

    int max_len=0;

    int first=0;

    unordered_map<int,int> m;   //stores prefix sum and index

    for(int i=0;i<n;i++)
    {
        sum+=arr[i];

        if(sum==0)
        {
            first=0;
            max_len=i+1;
        }

        if(m.find(sum)!=m.end())    //if the sum is seen already
        {
            if(max_len<i-m[sum])    //m[sum] gives first occurrence of sum
            {
                max_len=i-m[sum];
                first=m[sum]+1; //sub array starts from the next element onwards
            }
        }
        else
            m[sum]=i;
    }

    cout<<"max length: "<<max_len<<endl;

    cout<<"subarray:"<<endl;

    for(int i=first;i<first+max_len;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {-1, -2, 3, 15, -8, 1, 7, 10, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    longestSubarrayWithZeroSum(arr,n);

    return 0;
}
