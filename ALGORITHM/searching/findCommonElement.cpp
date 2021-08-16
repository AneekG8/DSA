//given three sorted arrays find the common elements
#include<iostream>
using namespace std;

void findCommon(int arr1[],int arr2[],int arr3[],int m,int n,int o)
{
    int i=0,j=0,k=0;

    while(i<m && j<n && k<o)
    {
        if(arr1[i]==arr2[j] && arr2[j]==arr3[k])
        {
            cout<<arr1[i]<<" ";
            i++;
            j++;
            k++;
        }
        if(arr1[i]<max(max(arr1[i],arr2[j]),arr3[k])) i++;

        if(arr2[j]<max(max(arr1[i],arr2[j]),arr3[k])) j++;

        if(arr3[k]<max(max(arr1[i],arr2[j]),arr3[k])) k++;
    }
}

int main()
{
    int ar1[] = {1, 5, 10, 20, 40, 80};
    int ar2[] = {6, 7, 20, 80, 100};
    int ar3[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    int n3 = sizeof(ar3)/sizeof(ar3[0]);

    cout << "Common Elements are ";
    findCommon(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}
