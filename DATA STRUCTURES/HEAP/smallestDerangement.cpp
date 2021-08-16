/*
Given the sequence  \S = {1, 2, 3,......,N} \
find the lexicographically smallest (earliest in dictionary order) derangement of \ S \ .
*/


#include<iostream>
#include<queue>
using namespace std;

void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int* smallestDerangement(int n)
{
    int* arr=new int[n];

    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<n;i++)
        pq.push(i+1);

    for(int i=0;i<n;i++)
    {
        int x=pq.top(); //first smallest
        pq.pop();

        if(x!=i+1 || i==n-1)
            arr[i]=x;
        else
        {
            arr[i]=pq.top(); //next smallest
            pq.pop();

            pq.push(x);     //push the previous element
        }
    }

    //check for the last(when n is odd)
    if(arr[n-1]==n && n!=1)
        swap(&arr[n-1],&arr[n-2]);

    return arr;
}

//we can optimize this method as the given sequence is very specific(1 to N ascending)
//!simple observation shows that we can simple swap a pair iterate to next pair

//thus if N is odd we do not process the last element at first rather we swap it with preceding element at last

//so we do at max N/2+1 swaps O(n)

int* smallestDerangement1(int n)
{
    int* arr=new int[n];

    for(int i=0;i<n;i++)
        arr[i]=i+1;

    for(int i=0;i<=n-2;i+=2)
        swap(&arr[i],&arr[i+1]);

    //for odd N
    if(arr[n-1]==n && n!=1)
        swap(&arr[n-1],&arr[n-2]);

    return arr;
}


int main()
{
    int n=5;

    int* arr=smallestDerangement1(n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}
