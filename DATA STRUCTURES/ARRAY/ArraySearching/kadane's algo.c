/*
Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void printarr(int *arr,int n)
{
	int i=0;
	while(n--)
	{
		printf("%d ",arr[i++]);
	}
	printf("\n");
}
int maxsum(int *arr,int n)
{
        int curr_sum = 0,max_sum = INT_MIN;

        for(int i=0;i<n;i++)
        {
            curr_sum += arr[i];

            max_sum = max(max_sum,curr_sum);

            curr_sum = max(0,curr_sum);
        }

        return max_sum;
}
int main()
{
    int a[] = {-2,-3,-4,-6,-1};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxsum(a, n);
    printf("%d\n",max_sum);
    return 0;
}
