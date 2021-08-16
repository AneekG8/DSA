/*
Write an efficient program to find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum.
*/
#include<bits/stdc++.h>
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
int maxsum(int *arr,int n)
{
        int curr_sum = 0,max_sum = INT_MIN;

        int s = 0,fin_s = -1,fin_e = -1;

        for(int i=0;i<n;i++)
        {
            curr_sum += arr[i];

            if(max_sum < curr_sum)
            {
                max_sum = curr_sum;

                fin_s = s;

                fin_e = i;
            }

            if(curr_sum < 0)
            {
                curr_sum = 0;

                s = i+1;
            }
        }

        for(int i=fin_s;i<=fin_e;i++)
            cout<<arr[i]<<" ";

        cout<<endl;

        return max_sum;
}
int main()
{
    int a[] = {-1,6,3,-6,7,-3,4};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxsum(a, n);
    printf("%d\n",max_sum);
    return 0;
}

