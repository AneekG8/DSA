#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void countSort(int arr[],int n)
{
    int max=*max_element(arr,arr+n);

    int min=abs(*min_element(arr,arr+n));

    int pos[max+1]={0};

    int neg[min+1]={0};

    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
            pos[arr[i]]++;

        else
            neg[abs(arr[i])]++;
    }

    int i=0,j=abs(*min_element(arr,arr+n)),k=0;

    while(i<n && j>=0)
    {
        if(neg[j])
            arr[i]=-j,neg[j]--,i++;
        else
            j--;
    }

    while(i<n)
    {
        if(pos[k])
            arr[i]=k,pos[k]--,i++;
        else
            k++;
    }
}

int main()
{
    int arr[] = { -5, -10, 0, -3, 8, 5, -1, 10 };
    int n=sizeof(arr)/sizeof(int);
    //cout<<abs(*min_element(arr,arr+n))<<endl<<*max_element(arr,arr+n)<<endl;
    countSort(arr,n);
    printArray(arr,n);
    return 0;
}
