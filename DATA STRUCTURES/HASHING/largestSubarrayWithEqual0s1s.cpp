//given an array with 0s and 1s only find out the largest sub array possible which has equal 0s and 1s

#include<bits/stdc++.h>
using namespace std;


//!approach brute force O(n^2)



//!approach hashing

//the trick is to use 0s as -1s

//so now we have an array of -1s and 1s....so any sub array with equal 0s(-1s) and 1s will have array sum of 0

//so the only problem is to find the largest sub array with 0 sum

void largestSubarray(int arr[],int n)
{
    unordered_map<int,int> m;

    int sum=0;

    int last;

    int max_len=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i])
            sum+=arr[i];
        else
            sum+=-1;    //in case of 0s

        if(sum==0)      //means number of -1s(0s) and 1s are equal
        {
            max_len=i+1;

            last=i;
        }

        if(m.find(sum)!=m.end())    //if same sum has occurred previously
        {
            if(max_len<i-m[sum])
            {
                max_len=i-m[sum];
                last=i;
            }
        }

        else
            m[sum]=i;   //store first occurrences of sums
    }

    cout<<"max length is: "<<max_len<<endl;

    cout<<"subarray is:"<<endl;

    for(int i=last-max_len+1;i<=last;i++)
        cout<<arr[i]<<" ";
}

int main()
{
    int arr[] = {  1,0,1,1,0,1 };
    int size = sizeof(arr) / sizeof(arr[0]);

    largestSubarray(arr, size);
    return 0;
}
