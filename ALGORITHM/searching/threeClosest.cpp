/*
Given three sorted arrays A[], B[] and C[], find 3 elements i, j and k from A, B and C respectively such that
max(abs(A[i] – B[j]), abs(B[j] – C[k]), abs(C[k] – A[i])) is minimized
*/

#include<iostream>
using namespace std;

void threeClosest(int arr1[],int arr2[],int arr3[],int p,int q,int r)
{
    int f,s,t;

    int diff=INT_MAX;

    int i=0,j=0,k=0;

    while(i<p && j<q && k<r)
    {
        int maximum=max(arr1[i],max(arr2[j],arr3[k]));
        int minimum=min(arr1[i],min(arr2[j],arr3[k]));

        if((maximum-minimum)<diff)
            f=arr1[i],s=arr2[j],t=arr3[k];

        if(arr1[i]==minimum)
            i++;
        else if(arr2[j]==minimum)
            j++;
        else
            k++;
    }

    cout<<f<<" "<<s<<" "<<t;
}

int main()
{
    int A[] = {1, 4, 10};
    int B[] = {2, 15, 20};
    int C[] = {10, 12};

    int p = sizeof A / sizeof A[0];
    int q = sizeof B / sizeof B[0];
    int r = sizeof C / sizeof C[0];

    threeClosest(A, B, C, p, q, r);
    return 0;
}
