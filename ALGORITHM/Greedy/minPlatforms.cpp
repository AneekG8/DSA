#include<bits/stdc++.h>
using namespace std;


int minPlatformsBrute(int arr[],int dep[],int n)
{
    int curr_p , res = INT_MIN;

    for(int i=0;i<n;i++)
    {
        curr_p = 1;
        for(int j=i+1;j<n;j++)
        {
            //find the overlaps
            if(!(arr[j]>=dep[i] || dep[j]<=arr[i]))
                curr_p++;
        }

        res = max(res,curr_p);
    }

    return res;
}

int minPlatforms(int arr[],int dep[],int n)
{
    int p = 0,res = INT_MIN;

    sort(arr,arr+n);
    sort(dep,dep+n);

    int i=0,j=0;

    while(i<n && j<n)
    {
        if(arr[i] <= dep[j])
        {
            p++;
            i++;
        }

        else if(arr[i] > dep[j])
        {
            p--;
            j++;
        }

        res = max(p,res);   //after each arrival or departure
    }

    return res;
}

int main()
{
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << minPlatformsBrute(arr, dep, n);
    return 0;
}
