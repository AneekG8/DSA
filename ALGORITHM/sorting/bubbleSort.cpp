//bubble sorting

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


void bubbleSort(int arr[],int n)
{
    for(int i=n-1;i>=1;i--)
    {
        bool swapped=false;

        for(int j=0;j<i;j++)
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]),swapped=true;

        if(!swapped)
            break;
    }
}


void bubbleSortRecur(int arr[],int n)
{
    if(n<=1)
        return;

    bool swapped=false;

    for(int j=0;j<n-1;j++)
        if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]),swapped=true;

    if(!swapped)
        return;

    bubbleSortRecur(arr,n-1);
}

int main()
{
    int arr[]={10,9,8,7,6};

    int size=sizeof(arr)/sizeof(int);

    bubbleSort(arr,size);

    printArray(arr,size);

    return 0;
}
