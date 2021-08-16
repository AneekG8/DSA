//pancake sorting

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

//an utility function: reverse array up to i
void flip(int arr[],int i)
{
    int l=0,h=i;
    while(l<h)
        swap(&arr[l],&arr[h]),l++,h--;
}


void pancakeSort(int arr[],int n)
{
    int curr_size=n;

    while(curr_size>1)
    {
        int ind=max_element(arr,arr+curr_size)-arr;

        flip(arr,ind);

        flip(arr,curr_size-1);

        curr_size--;
    }
}

int main()
{
    int arr[] = {23, 10, 20,40, 11, 12, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    pancakeSort(arr, n);

    cout<<"Sorted Array "<<endl;
    printArray(arr, n);

    return 0;
}
