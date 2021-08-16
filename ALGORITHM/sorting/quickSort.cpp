//quick sort

#include<iostream>
#include<stack>

using namespace std;

void swap(int* a,int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}


//function for partition

int partition1(int arr[],int l,int h)
{
    int i=l,j=h,pivot=arr[h];

    while(i<j)
    {
        while(i<=h && arr[i]<=pivot)    //it can exceed the higher bound
            i++;

        while(arr[j]>pivot)     //it cannot exceed the lower bound as we are looking for smaller or *equal* to element
            j--;

        if(i<j)
            swap(&arr[i],&arr[j]);
    }

    swap(&arr[l],&arr[j]);

    return j;
}


int partition2(int arr[],int l,int h)
{
    int pivot=arr[l];

    int i=h+1;

    for(int j=h;j>=l+1;j--)
    {
        if(arr[j]>pivot)
        {
            i--;
            swap(&arr[i],&arr[j]);
        }
    }
    //arr[i] will be first element int the array that is greater than pivot
    swap(&arr[l],&arr[i-1]);

    return i-1;
}


void partition3way(int arr[],int l,int h,int* next_l,int* next_h)
{
    int low=l,mid=l,high=h,pivot=arr[l];

    while(mid<=high)
    {
        if(arr[mid]<pivot)
            swap(&arr[low],&arr[mid]),low++,mid++;

        else if(arr[mid]==pivot)
            mid++;

        else
            swap(&arr[high],&arr[mid]),high--;
    }

    *next_h=low-1;
    *next_l=high+1;
}


void quickSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int next_l,next_h;

        partition3way(arr,l,h,&next_l,&next_h);

        quickSort(arr,l,next_h);

        quickSort(arr,next_l,h);
    }
}

void quickSortItr(int arr[],int l,int h)
{
    stack<int> s;

    //stack is used keep track of the lower and the higher bound of the part of the array to be sorted
    s.push(l);
    s.push(h);

    while(!s.empty())
    {
        int high=s.top();
        s.pop();

        int low=s.top();
        s.pop();

        int p=partition2(arr,low,high);

        //if there are elements left to be sorted on left
        if(p-1>low)
        {
            s.push(low);
            s.push(p-1);
        }

        if(p+1<high)
        {
            s.push(p+1);
            s.push(high);
        }
    }
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Driver Code
int main()
{
    int arr[] = {50,50,70,60,90,40,50,80,40,10,20,30,90};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSortItr(arr, 0, n - 1);
    cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}
