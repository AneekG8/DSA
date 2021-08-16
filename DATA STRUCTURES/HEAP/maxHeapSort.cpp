#include "maxHeap.h"

using namespace std;

void maxHeapSort(int arr[],int n)
{
    maxHeap h(arr,n);

    for(int i=0;i<n-1;i++)
        h.pop();
}

void maxHeapify(int arr[],int n,int i)
{
    while(i < n)
    {
        int largest = i,left = 2*i+1, right = 2*i+2;

        if(left < n && arr[largest] < arr[left])
            largest = left;

        if(right < n && arr[largest] < arr[right])
            largest = right;

        if(i == largest)
            break;

        swap(arr+largest,arr+i);

        i =largest;
    }
}

void buildMaxHeap(int arr[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        maxHeapify(arr,n,i);
}

void maxHeapSortItr(int arr[],int n)
{
    buildMaxHeap(arr,n);

    while(n > 1)
    {
        swap(arr,arr+n-1);

        n--;

        maxHeapify(arr,n,0);
    }
}

int main()
{
    int arr[] = {1,0,3,-19,78,56,70,100,-100};

    int n = sizeof(arr)/sizeof(int);

    maxHeapSortItr(arr,n);

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}
