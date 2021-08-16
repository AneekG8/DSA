//recursive linear search

#include<iostream>
using namespace std;

int recurLinearSearch(int arr[],int l,int r,int x)
{
    if(l>r)
        return -1;

    if(arr[l]==x)
        return l;

    if(arr[r]==x)
        return r;

    return recurLinearSearch(arr,l+1,r-1,x);
}

int main()
{
    int arr[] = {12, 34, 54,55, 2, 3}, i;
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 55;
    int index = recurLinearSearch(arr, 0, n - 1, x);
    if (index != -1)
    cout << "Element " << x
         << " is present at index "
         << index;
    else
        cout << "Element " << x
             << " is not present" ;
    return 0;
}
