//given a number a k and an array arr find the max unique element present in every contiguous sub array of size k

#include<bits/stdc++.h>
using namespace std;

//!method: sliding window technique

void findUniqueMaxSubArr(int arr[],int n,int k)
{

    if(k>n)
        return;

    map<int,int> count;     //to store count of the elements in a window

    set<int> s;     //this keeps track of the unique elements in that window

    //first we process for the first k-1 elements(so we can start from kth element and move the window accordingly)

    //store counts for k-1 elements
    for(int i=0;i<k-1;i++)
        count[arr[i]]++;

    //now insert the unique elements
    for(auto x : count)
    {
        //if count == 1
        if(x.second==1)
            s.insert(x.first);
    }

    //start from k-1th element
    for(int i=k-1;i<n;i++)
    {
        //now we have k-1 elements processed

        //so we go for kth element

        //store count
        count[arr[i]]++;

        //update set
        if(count[arr[i]]==1)
            s.insert(arr[i]);
        else
            s.erase(arr[i]);

        //print the max from set(all distinct)
        if(s.size()==0)
            cout<<"Nothing ";

        //last element of set is the maximum
        else
            cout<<*s.rbegin()<<" ";

        //now we have to delete the first element of this window
        //so that the remaining elements are the k-1 elements of next window

        //also we make sure the rest k-1 elements are processed

        //update count
        count[arr[i-k+1]]--;     //i-k+1 is the first element of current window

        //update set
        if(count[arr[i-k+1]]==1)
            s.insert(arr[i-k+1]);

        else if(count[arr[i-k+1]]==0)
            s.erase(arr[i-k+1]);

    }
}

int main()
{
    int a[] = { 3,3,3,4,4,2};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 4;
    findUniqueMaxSubArr(a, n, k);
    return 0;
}
