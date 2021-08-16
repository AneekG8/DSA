//find frequency of a number in sorted array

#include<bits/stdc++.h>
using namespace std;

void getCount(int arr[],int l,int h,int x,int* c)
{
    if(h>=l)
    {
        int mid = (l+h)/2;

        if(arr[mid]==x)
        {
            (*c)++;
            getCount(arr,mid+1,h,x,c);
            getCount(arr,l,mid-1,x,c);
        }

        else if(arr[mid]<x)
            getCount(arr,mid+1,h,x,c);

        else
            getCount(arr,l,mid-1,x,c);
    }
}


int getCount(int arr[],int n,int x)
{
    int c=0;

    getCount(arr,0,n-1,x,&c);

    return c;
}

int main()
{
  int arr[] = {1, 2, 2, 3, 3, 3, 3,3};
  int x =  3;  // Element to be counted in arr[]
  int n = sizeof(arr)/sizeof(arr[0]);
  int c = getCount(arr,n,x);
  printf(" %d occurs %d times ", x, c);
  return 0;
}
