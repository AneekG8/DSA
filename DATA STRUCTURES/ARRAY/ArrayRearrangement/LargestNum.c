//FIND THE LARGEST NUMBER POSSIBLE FROM A GIVEN SET OF INTEGERS

/*
In the used sorting algorithm, instead of using the default comparison, write a comparison function myCompare() and use it to sort numbers.
Given two numbers X and Y, how should myCompare() decide which number to put first – we compare two numbers XY (Y appended at the end of X)
and YX (X appended at the end of Y). If XY is larger, then X should come before Y in output, else Y should come before. For example, let X and Y be 542 and 60.
To compare X and Y, we compare 54260 and 60542. Since 60542 is greater than 54260,we put Y first.


IDEA: sort the array in a way such that X > Y => XY > YX
*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int count(int n)					//returns no. of digits
{
	int count=0;
	while(n!=0)
	{
		count++;
		n=n/10;
	}
	return count;
}
void printarr(int n,int *arr)
{
	int i=0;
	while(i < n)
	{
		printf("%d",*(arr+i));
		i++;
	}
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int compare(int a,int b)
{
	if((a*pow(10,count(b))+b)>(b*pow(10,count(a))+a))
		return 0;
	else
		return 1;
}
void sort(int n,int *arr)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(compare(arr[i],arr[j]))
				swap(&arr[i],&arr[j]);
		}
	}
}
int main()
{
	int arr[]={1, 34, 3, 98, 9, 76, 45, 4};
	int n=sizeof(arr)/sizeof(int);
	sort(n,arr);
	printarr(n,arr);
	return 0;
}
