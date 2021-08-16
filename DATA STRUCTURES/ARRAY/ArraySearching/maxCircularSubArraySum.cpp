#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[], int n){

        // Your code here
        int curr_sum = 0,max_sum = INT_MIN;

        for(int i=0;i<n;i++)
        {
            curr_sum += arr[i];

            max_sum = max(max_sum,curr_sum);

            curr_sum = max(0,curr_sum);
        }

        return max_sum;

    }

    int reverse_kadane(int arr[], int n){   //min sub array sum

        // Your code here
        int curr_sum = 0,min_sum = INT_MAX;

        for(int i=0;i<n;i++)
        {
            curr_sum += arr[i];

            min_sum = min(min_sum,curr_sum);

            curr_sum = min(0,curr_sum);
        }

        return min_sum;

    }


//BRUTE FORCE APPROACH

int maxSumBF(int arr[],int n)
{
    int max_sum  = INT_MIN;

    for(int i=0;i<n;i++)
    {
        int curr_sum = 0,j=i;

        for(int c=0;c<n;c++)
        {
            curr_sum += arr[j];

            max_sum = max(max_sum,curr_sum);

            j = (j+1) % n;
        }
    }

    return max_sum;
}

//optimal approach using kadane's algo

    int circularSubarraySum(int arr[], int n){

        // your code here

        int sum = 0;

        for(int i=0;i<n;i++)
        {
            sum += arr[i];
        }

        int one = kadane(arr,n);

        int two = sum - reverse_kadane(arr,n);

        if(one < 0)
            return one;

        return max(one,two);

    }



int main()
{
    int arr[] = {2,-1,3,-10,3,2,4,-2,-3,-1,7};

    int n = sizeof(arr)/sizeof(int);

    cout<<maxSumBF(arr,n);
}
