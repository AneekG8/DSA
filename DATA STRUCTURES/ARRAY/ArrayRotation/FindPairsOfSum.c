/*
find number of pairs from a sorted rotated array which add up to the given sum
Find the pivot element of the sorted and the rotated array. The pivot element is the largest element in the array. The smallest element will be adjacent to it.
Use two pointers (say left and right) with the left pointer pointing to the smallest element and the right pointer pointing to largest element.
Find the sum of the elements pointed by both the pointers.
If the sum is equal to x, then increment the count. If the sum is less than x, then to increase sum move the left pointer to next position by incrementing it in a rotational manner. If the sum is greater than x, then to decrease sum move the right pointer to next position by decrementing it in rotational manner.
Repeat step 3 and 4 until the left pointer is not equal to the right pointer or until the left pointer is not equal to right pointer – 1.
Print final count.
*/
#include<stdio.h>
#include<stdlib.h>
int findpivot(int n,int *arr)
{
	int i;
	for(i=0;i<n-1;i++)
	{
		if(*(arr+i)>*(arr+i+1))
			break;
	}
	return i;
}
int findpairs(int n,int sum,int *arr)
{
	int l = findpivot(n,arr);
	int r = l+1;
	int count=0;
	while(l!=r)
	{
		if(*(arr+l)+*(arr+r) == sum)
		{
			count++;
			if(r == (l - 1 + n) % n){
                return count;
            }

            r = (r + 1) % n;
            l = (l - 1 + n) % n;
		}
		else if(*(arr+l)+*(arr+r) < sum)
		{
			r = (r+1)%n;
		}
		else if(*(arr+l)+*(arr+r) > sum)
		{
			l=(n+l-1)%n;
		}
	}
	return count;
}
int main()
{
	int arr[]={5,6,7,8,9,10,1,2,3,4};
	int n=sizeof(arr)/sizeof(int);
	int sum=9;
	printf("there are %d pairs whose sum is %d\n",findpairs(n,sum,arr),sum);
	return 0;
}
