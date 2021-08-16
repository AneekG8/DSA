//selection sort

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

//select minimum in each iteration and place at the first of the current sub array
void selectionSort(int arr[],int n)
{
    for(int i=0;i<=n-2;i++)
    {
        int minInd=i;

        for(int j=i+1;j<n;j++)
            if(arr[j]<arr[minInd])
                minInd=j;

        //swap
        swap(&arr[i],&arr[minInd]);
    }
}

int main()
{
    int arr[]={1,5,3,0,8,4,3};

    int size=sizeof(arr)/sizeof(int);

    selectionSort(arr,size);

    printArray(arr,size);

    return 0;
}
