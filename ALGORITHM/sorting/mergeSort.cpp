//merge sort

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


//merge function
void merge(int arr[],int l,int m,int r)
{
    int temp[r-l+1];

    int i=l,j=m+1,k=0;

    while(i<=m && j<=r)
    {
        if(arr[i]<arr[j])
            temp[k++]=arr[i++];
        else
            temp[k++]=arr[j++];
    }

    while(i<=m)
        temp[k++]=arr[i++];

    while(j<=r)
        temp[k++]=arr[j++];

    for(int i=l,j=0;i<=r;i++)
        arr[i]=temp[j++];
}

void mergeSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;

        mergeSort(arr,l,mid);

        mergeSort(arr,mid+1,h);

        merge(arr,l,mid,h);
    }
}


void mergeSortItr(int arr[],int n)
{
    int p,i;

    for(p=2;p<=n;p*=2)
    {
        for(i=0;i+p-1<n;i+=p)
        {
            int l=i;
            int h=i+p-1;
            int mid=(l+h)/2;

            merge(arr,l,mid,h);
        }

        //!number of unprocessed elements left
        if(n-i>p/2)
        {
            int l=i;
            int h=i+p-1;
            int mid=(l+h)/2;

            merge(arr,l,mid,n-1);
        }
    }

    if(p/2<n)
        merge(arr,0,p/2-1,n-1);
}

int main()
{
    int arr[]={3,1,5,6,3,9,0};

    int n=sizeof(arr)/sizeof(int);

    mergeSortItr(arr,n);

    printArray(arr,n);

    return 0;
}
