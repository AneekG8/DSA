/*
Given an unsorted array of positive integers. Find the number of triangles that can be formed with three different array elements as three sides of triangles:

1. Sort the array in non-decreasing order.

2. Initialize two pointers ‘i’ and ‘j’ to first and second elements respectively, and initialize count of triangles as 0.

3. Fix ‘i’ and ‘j’ and find the rightmost index ‘k’ (or largest ‘arr[k]’) such that ‘arr[i] + arr[j] > arr[k]’. The number of triangles that can be
 formed with ‘arr[i]’ and ‘arr[j]’ as two sides is ‘k – j’. Add ‘k – j’ to count of triangles.

Let us consider ‘arr[i]’ as ‘a’, ‘arr[j]’ as b and all elements between ‘arr[j+1]’ and ‘arr[k]’ as ‘c’. The above mentioned conditions (ii) and
 (iii) are satisfied because ‘arr[i] < arr[j] < arr[k]'. And we check for condition (i) when we pick 'k'

4. Increment ‘j’ to fix the second element again.

Note that in step 3, we can use the previous value of ‘k’. The reason is simple, if we know that the value of ‘arr[i] + arr[j-1]’ is greater than ‘arr[k]’,
 then we can say ‘arr[i] + arr[j]’ will also be greater than ‘arr[k]’, because the array is sorted in increasing order.

5. If ‘j’ has reached end, then increment ‘i’. Initialize ‘j’ as ‘i + 1’, ‘k’ as ‘i+2’ and repeat the steps 3 and 4.
*/
#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sort(int n,int *arr)									//this is not an O(nlogn) sorting
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(arr[i]>arr[j])
				swap((arr+i),(arr+j));
		}
	}
}
int findtriangles(int n,int *arr)
{
	sort(n,arr);
	int i=0,j,k,count=0;
	while(i<n-2)
	{
		j=i+1,k=j+1;
		while(j<n-1)
		{
			//k=j+1;
			while(arr[i]+arr[j]>arr[k] && k<n)
			{
				k++;
			}
			count+=k-j-1;
			j++;
		}
		i++;
	}
	return count;
}
int main()
{
	 int arr[] = {10, 21, 22, 100, 101, 200, 300};
    int n = sizeof( arr ) / sizeof( arr[0] );

    printf("Total number of triangles possible is %d ",
        findtriangles( n,arr ) );

    return 0;

}
