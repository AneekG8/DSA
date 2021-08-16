/*
Let us calculate initial value of i*arr[i] with no rotation
R0 = 0*arr[0] + 1*arr[1] +...+ (n-1)*arr[n-1]

After 1 rotation arr[n-1], becomes first element of array,
arr[0] becomes second element, arr[1] becomes third element
and so on.
R1 = 0*arr[n-1] + 1*arr[0] +...+ (n-1)*arr[n-2]

R1 - R0 = arr[0] + arr[1] + ... + arr[n-2] - (n-1)*arr[n-1]

After 2 rotations arr[n-2], becomes first element of array,
arr[n-1] becomes second element, arr[0] becomes third element
and so on.
R2 = 0*arr[n-2] + 1*arr[n-1] +...+ (n-1)*arr[n-3]

R2 - R1 = arr[0] + arr[1] + ... + arr[n-3] - (n-1)*arr[n-2] + arr[n-1]

If we take a closer look at above values, we can observe
below pattern

Rj - Rj-1 = arrSum - n * arr[n-j] /////////this is the formula derived for jth rotation

Where arrSum is sum of all array elements, i.e.,

arrSum = &Sum; arr[i]
        0<=i<=n-1
*/
#include<stdio.h>
#include<stdlib.h>
int getsum(int n,int *arr)
{
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum += i*arr[i];
	}
	return sum;
}
int getmaxsum(int n,int *arr)
{
	int maxsum,cursum,arrsum,i;
	arrsum=0;
	for(i=0;i<n;i++)
	{
		arrsum += *(arr+i);
	}
	cursum=maxsum=getsum(n,arr);
	for(i=1;i<n;i++)
	{
		if(maxsum<cursum+arrsum-n*arr[n-i])                          //cursum is the getsum value of prev rotation
			maxsum=cursum+arrsum-n*arr[n-i];		      			//cursum+arrsum-n*arr[n-i] is the getsum value of ith rotation
	}
	return maxsum;
}

int getmaxsum1(int n,int arr[])
{
    int r0 = getsum(n,arr);

    int arrSum = 0,maxSum = r0;

    for(int i=0;i<n;i++)
        arrSum += arr[i];

    for(int r=1;r<n;r++)
    {
        int curr_sum = r0 + n*arr[r-1] - arrSum;

        maxSum = maxSum < curr_sum ? curr_sum : maxSum;
    }

    return maxSum;
}
int main()
{
	int arr[]={10,1,2,3,4,5,6,7,8,9};
	int n=sizeof(arr)/sizeof(int);
	printf("%d\n",getmaxsum1(n,arr));
	return 0;
}
