#include<iostream>

using namespace std;


int binCoeff(int n,int k)
{
    k = min(k,n-k);

    int size = k+1;     //take n/2+1 to compute over whole domain of k

    int arr[size];

    arr[0]=1;   //base

    for(int k = 1;k < size;k++)
    {
        arr[k] = ((n-k+1)*arr[k-1])/k;
    }

    return arr[k];
}


int main()
{
    cout<<binCoeff(778,116);

    return 0;
}
