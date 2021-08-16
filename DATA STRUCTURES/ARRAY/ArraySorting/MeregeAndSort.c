#include<stdio.h>
#include<stdlib.h>
#define NA -1
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void printarr(int n,int *arr)
{
	int i=0;
	while(i < n)
	{
		printf("%d ",*(arr+i));
		i++;
	}
	printf("\n");
}
void movetoend(int n,int *arr)
{
	int i,j=n-1;
	for(i=n-1;i>=0;i--)
	{
		if(arr[i]!=-1)
		{
			arr[j]=arr[i];
			j--;
		}
		else
			continue;
	}
}
void mergesort(int m,int n,int *arr1,int *arr2)
{
	int i,j=n,x=arr2[n];
	for(i=0;i<n;i++)
	{
		if(arr1[i]<x)
		{
			arr2[i]=arr1[i];
		}
		else
		{
			while(arr2[j]<arr1[i]&&j<m+n)
			{
				arr2[j-1]=arr2[j];
				j++;
			}
			j--;
			arr2[j]=arr1[i];
		}
	}

}

void movetoend1(int n,int arr[])
{
    int j=n;
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i] != -1)
            j--,swap(arr+i,arr+j);
    }
}
int main()
{
  /* Initialize arrays */
  int mPlusN[] = {2, 8, NA, NA, NA, 13, NA, 15, 20};
  int N[] = {5, 7, 9, 25};
  int n = sizeof(N)/sizeof(N[0]);
  int m = sizeof(mPlusN)/sizeof(mPlusN[0]) - n;

  /*Move the m elements at the end of mPlusN*/
  movetoend1(m+n,mPlusN);
  printarr(m+n,mPlusN);

  /*Merge N[] into mPlusN[] */
  mergesort(m,n,N,mPlusN);

  /* Print the resultant mPlusN */
  printarr(m+n,mPlusN);

  return 0;
}
