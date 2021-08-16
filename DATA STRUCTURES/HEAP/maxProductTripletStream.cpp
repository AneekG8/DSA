//find the maximum product of a triplet from a stream

#include<bits/stdc++.h>
using namespace std;

int& Min(int& a,int& b,int& c)
{
    if(a<=b && a<=c)
        return a;
    else if(b<=a && b<=c)
        return b;
    else return c;
}
void maxProductTripletStream(int arr[],int n)
{
    priority_queue<int,vector<int>,greater<int>> pq;

    int p=1;

    for(int i=0;i<n;i++)
    {
        if(i<2)
        {
            cout<<"-1 ";

            p*=arr[i];

            pq.push(arr[i]);
        }
        else if(i==2)
        {
            p=p*arr[i];

            cout<<p<<" ";

            pq.push(arr[i]);
        }
        else
        {
            if(arr[i]>pq.top())
            {
                p=p/pq.top()*arr[i];
                pq.pop();
                pq.push(arr[i]);
            }
            cout<<p<<" ";
        }
    }
}


//using three variables O(n)
void maxProductTripletStream1(int arr[],int n)
{
    int a=arr[0],b=arr[1],c=arr[2];

    for(int i=0;i<n;i++)
    {
        if(i<2)
        {
            cout<<"-1 ";
        }
        else if(i==2)
        {
            cout<<a*b*c<<" ";
        }
        else
        {
            if(arr[i]>Min(a,b,c))
            {
                Min(a,b,c)=arr[i];
            }
            cout<<a*b*c<<" ";
        }
    }
}
int main()
{
    int arr[] = {2,4,3,1,6,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    maxProductTripletStream1(arr, n);
    return 0;
}
