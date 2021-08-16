#include<bits/stdc++.h>

using namespace std;

int days(int arr[],int n)
{
    int mx = INT_MIN;

    int res = 0;

    for(int i=0;i<n;i++)
    {
        if(i == n-1)
        {
            if(arr[i] > mx)
                res++;
        }
        else
        {
            if(arr[i] > arr[i+1] && arr[i] > mx)
                res++;
        }

        mx = max(mx,arr[i]);
    }

    return res;
}

int main()
{
    int T;
    cin>>T;

    int t=1;

    while(t<=T)
    {
        int n;
        cin>>n;

        int arr[n];

        for(int i=0;i<n;i++)
            cin>>arr[i];

        cout<<"Case #"<<t<<": "<<days(arr,n)<<endl;

        t++;
    }
}
