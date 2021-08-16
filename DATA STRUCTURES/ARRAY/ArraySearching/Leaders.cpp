/*

Write a program to print all the LEADERS in the array.
An element is leader if it is greater than all the elements to its right side. And the rightmost element is always a leader
ALGO:-
Scan all the elements from right to left in an array and keep track of maximum till now.When maximum changes its value, print it.
*/
#include<iostream>
using namespace std;
void printarr(int *arr,int n)
{
	int i=0;
	while(n--)
	{
		printf("%d ",arr[i++]);
	}
	printf("\n");
}
void printleaders(int *arr,int n)
{
	int max=arr[n-1];
	cout<<"leaders are:"<<endl;
	cout<<arr[n-1]<<endl;
	for(int i=n-2;i>=0;i--)
	{
		if(arr[i]>max)
		{
			max=arr[i];
			cout<<max<<endl;
		}
	}
}
int main() 
{ 
    int arr[] = {24,16, 17, 4, 3, 5, 2,1}; 
    int n = sizeof(arr)/sizeof(arr[0]);
	printarr(arr,n); 
    printleaders(arr, n); 
    return 0; 
} 
