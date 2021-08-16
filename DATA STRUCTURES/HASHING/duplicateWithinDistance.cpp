//given an array and a value k find if the array has any duplicate within k distance

// https://practice.geeksforgeeks.org/problems/kth-distance3757/1#

#include<bits/stdc++.h>
using namespace std;

bool checkDuplicatesWithinK(int arr[],int n,int k)
{
    if(n==1)
        return false;

    unordered_map<int,int> m;

    for(int i=0;i<n;i++)
    {
        if(m.find(arr[i])==m.end())
            m[arr[i]]=i;
        else
        {
            if(i-m[arr[i]]<=k)  //distance between next and previous occurrence is < k
                return true;

            //else update last occurrence
            else
                m[arr[i]]=i;
        }
    }

    return false;
}

int main()
{
    int arr[] = {10, 5, 3, 4, 10, 5, 6,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (checkDuplicatesWithinK(arr, n, 3))
        cout << "Yes";
    else
        cout << "No";
}
