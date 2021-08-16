#include<bits/stdc++.h>

using namespace std;

int smallestSum(int arr[],int n)
{
    int min_sum = INT_MAX, curr_sum = 0;

    for(int i=0;i<n;i++)
    {
        curr_sum += arr[i];
        min_sum = min(curr_sum,min_sum);
        curr_sum = min(curr_sum,0);
    }

    return min_sum;
}
