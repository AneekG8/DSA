//given n-1 numbers from 1 to n find the missing one

#include<iostream>
using namespace std;

//method 1: n(n+1)/2 - arraySum     ////can be optimized the overflow dispute GFG

//method 2: using XOR ////XOR between all the n-1 terms themselves yield 0 resulting the missing number


int findMissing(int arr[],int n)
{
    int a=1;
    int b=arr[0];

    for(int i=2;i<=n;i++)
    {
        a=a^i;
        if(i!=n)
            b=b^arr[i-1];
    }

    return a^b;
}

int main()
{
    int arr[] = { 1, 2,3 ,4, 5, 6 ,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    int miss = findMissing(arr, n);
    cout << miss;
}
