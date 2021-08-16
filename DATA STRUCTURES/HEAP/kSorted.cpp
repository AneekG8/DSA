//sort a k sorted array

#include<bits/stdc++.h>
using namespace std;

// Prototype of a utility function to swap two integer
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}


//using insertion sort || O(nk) time

void insertionSort(int arr[],int n,int k)
{
    for(int i=1;i<n;i++)
    {
        int j=i;

        while(j!=0 && arr[j]<arr[j-1])  //this will take max O(k) time
        {
            swap(&arr[j],&arr[j-1]);
            j--;
        }
    }
}


//!method 2 using MinHeap

//the first element of the sorted array will lie under 0+k th index
//that is the first element of sorted array will be found among the first k+1 elements
//!so we create a minHeap with first k+1 elements (upper bound is the only concern)

//now we extract the min element and store that in arr[0]
//we repeat the process for all the rest elements (add next to heap and pop one)

//!note as we forward through sorted and actual array simultaneously the upper bound pattern is always maintained

void sortK(int arr[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>> pq(arr,arr+k+1);

    int j=0;
    for(int i=k+1;i<n;i++)
    {
        arr[j++]=pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    //store rest of the elements sorted
    while(!pq.empty())
    {
        arr[j++]=pq.top();
        pq.pop();
    }
}
//!we could have used BST also
//time: O(nlogk)  space:O(k)


void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}




int main()
{
    int k = 4;
    int arr[] = { 10, 9, 8, 7, 4, 70, 60, 50 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortK(arr, n, k);

    cout << "Following is sorted array" << endl;
    printArray(arr, n);

    return 0;
}
