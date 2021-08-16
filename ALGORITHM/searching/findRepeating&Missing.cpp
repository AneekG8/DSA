//given an array of integers from 1 to n (except one repeating and one missing) find the repeating and missing elements

#include<iostream>
using namespace std;

//method 1: sorting O(nlogn)

//method 2: hashing || count array O(n)

//method 3: marking elements in array O(n)

void findRepeatingAndMissing(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[abs(arr[i])-1] < 0)
            cout<<"repeating element: "<<abs(arr[i])<<endl;
        else
            arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
    }

    for(int i=0;i<n;i++)
    {
        if(arr[i]>0)
        {
            cout<<"missing element: "<<i+1;
            break;
        }
    }
}

//method 5: building equations
void findRepeatingAndMissing2(int arr[],int n)
{
    //suppose x is missing number and y is repeating number
    int S=(n*(n+1))/2;
    int Sq=(n*(n+1)*(2*n+1))/6;

    for(int i=0;i<n;i++)
        S -= arr[i],Sq -= (arr[i]*arr[i]);

    //now we have
    //x-y = S
    //x^2-y^2 = Sq

    int diff = S;
    int sum = Sq/S;

    cout<<"missing number: "<<(sum+diff)/2<<endl;

    cout<<"repeating number: "<<(sum-diff)/2;
}
//other methods: build equations || use XOR

int main()
{
    int arr[] = { 7, 3, 4, 5, 5, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findRepeatingAndMissing2(arr, n);
}
