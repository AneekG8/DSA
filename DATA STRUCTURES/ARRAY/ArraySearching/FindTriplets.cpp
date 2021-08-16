/*
Given an array of distinct elements. The task is to find triplets in array whose sum is zero
ALGO:-
1. Sort all element of array
2. Run loop from i=0 to n-2.
     Initialize two index variables l=i+1 and r=n-1
4. while (l < r) 
     Check sum of arr[i], arr[l], arr[r] is
     zero or not if sum is zero then print the
     triplet and do l++ and r--.
5. If sum is less than zero then l++
6. If sum is greater than zero then r--
7. If not exist in array then print not found.
*/
#include<bits/stdc++.h>
using namespace std;
void findTriplets(int *arr,int n)
{
	bool s=false;
	sort(arr,arr+n);
	for(int i=0;i<n-2;i++)
	{
		int l=i+1,r=n-1;
		while(l<r)
		{
			int curr_sum=arr[i]+arr[l]+arr[r];
			if(curr_sum<0)
			{
				l++;
			}
			else if(curr_sum>0)
			{
				r--;
			}
			else
			{
				printf("%d + %d + %d = 0\n",arr[i],arr[l],arr[r]);
				l++;
				r--;
				s=true;
			}
		}
	}
	if(s==false)
		printf("not found!\n");
}
int main()
{
	int arr[] = {1, -1, 0, 4, -5}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    findTriplets(arr,n); 
    return 0; 
}
