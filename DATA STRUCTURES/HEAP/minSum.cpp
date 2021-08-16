//given an array find out the minimum sum possible of two numbers made from the digits of array

#include<bits/stdc++.h>
using namespace std;

//approach

//we need to find the smallest digit from the remaining array
//the smallest digit will be leading number of the numbers(alternatively)

//we an use a min heap and extract two minimum at a time
//or we can sort the array (ascending) and alternatively pick leading digits of the numbers
int minSum(int arr[],int n)
{
    priority_queue<int,vector<int>,greater<int>> pq(arr,arr+n);

    int num1=0,num2=0;

    while(!pq.empty())
    {
        num1=num1*10+pq.top();
        pq.pop();

        if(pq.empty())
            break;

        num2=num2*10+pq.top();
        pq.pop();
    }

    return num1+num2;
}

int main()
{
    int arr[] = {5,3,0,7,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<minSum(arr, n)<<endl;
    return 0;
}
