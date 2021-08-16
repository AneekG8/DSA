/*
1. Nav­i­gate the array.
2. Check if a[i] = -1, if yes then ignore it.
3. If a[i] != -1, Check if element a[i] is at its cor­rect posi­tion (i=A[i]). If yes then ignore it.
4. If a[i] != -1 and ele­ment a[i] is not at its cor­rect posi­tion (i!=A[i]) then place it to its correct posi­tion, but there are two conditions:

Either A[i] is vacate, means A[i] = -1, then just put A[i] = i .
OR A[i] is not vacate, means A[i] = x, then int y=x put A[i] = i. Now, we need to place y to its cor­rect place, so repeat from step 3.
*/
#include<stdio.h>
#include<stdlib.h>
void rearr(int n,int *arr)
{
	int i,temp,y;
	for(i=0;i<n;i++)
	{
		if(arr[i]==-1||arr[i]==i)
			continue;
		else
		{
			if(arr[arr[i]]==-1)
				arr[arr[i]]=arr[i];
			else
			{
				y=arr[arr[i]];
				arr[arr[i]]=arr[i];
				arr[y]=y;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(arr[i]!=i)
			arr[i]=-1;
		else
		continue;
	}
}
void printarr(int n,int *arr)
{
	int i=0;
	while(i < n)
	{
		printf("%d ",*(arr+i));
		i++;
	}
}
int main()
{
	int arr[]= {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
	int n=sizeof(arr)/sizeof(int);
	rearr(n,arr);
	printarr(n,arr);
	return 0;
}
