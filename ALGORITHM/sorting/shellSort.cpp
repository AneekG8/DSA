#include<bits/stdc++.h>

using namespace std;

void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

void printArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}


void shellSort(int arr[],int n)
{
    for(int gap=n/2;gap>0;gap/=2)
    {
        //gapped insertion
        for(int i=gap;i<n;i++)
        {
            //int temp=arr[i];
            int j=i-gap;

            while(j>=0 && arr[j]>arr[j+gap])
            {
                swap(&arr[j],&arr[j+gap]);
                j=j-gap;
            }
        }
    }
}

int main()
{
    int arr[] = {12, 34, 54, 2, 3}, i;
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before sorting: \n";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "\nArray after sorting: \n";
    printArray(arr, n);

    return 0;
}
