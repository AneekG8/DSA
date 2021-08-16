//insertion sort

#include<iostream>
using namespace std;

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}

void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i;

        while(j>0 && arr[j]<arr[j-1])
            swap(&arr[j],&arr[j-1]),j--;
    }
}

void insertionSortRecur(int arr[],int n)
{
    if(n<=1)
        return;

    insertionSort(arr,n-1);

    int j=n-1;

    while(j>0 && arr[j]<arr[j-1])
        swap(&arr[j],&arr[j-1]),j--;

}


int main()
{
    int arr[]={1,4,5,0};

    int size=sizeof(arr)/sizeof(int);

    insertionSort(arr,size);

    printArray(arr,size);

    return 0;
}
