//given an array a sum find pairs which add up to the given sum

#include<bits/stdc++.h>
using namespace std;

//O(n^2) BRUTE FORCE APPROACH

//O(n * logn) BRUTE FORCE using BINARY SEARCH for sum-arr[i]

//O(nlogn) for unsorted using SORTING and TWO POINTER technique || O(n) if already sorted


//O(n) using hashing
void findPairSum(int arr[],int n,int sum)
{
    unordered_set<int> s;

    for(int i=0;i<n;i++)
    {
        if(s.find(sum-arr[i])!=s.end())
            cout<<arr[i]<<" + "<<sum-arr[i]<<" = "<<sum<<endl;

        s.insert(arr[i]);
    }
}
//time O(n)

int main()
{
    int A[] = { 1, 4, 45, 6, 10, 8 , 12 , -29};
    int n = 16;
    int arr_size = sizeof(A) / sizeof(A[0]);

    // Function calling
    findPairSum(A, arr_size, n);

    return 0;
}
