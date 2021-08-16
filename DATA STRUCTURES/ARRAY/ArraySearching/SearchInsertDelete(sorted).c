#include<stdio.h>
#include<stdlib.h>
void printarr(int *arr,int n)
{
	int i=0;
	while(n--)
	{
		printf("%d ",arr[i++]);
	}
	printf("\n");
}
//Time Complexity: O(log n)
int binarysearch(int *arr,int low,int high,int key)
{
	if(high<low)
		return -1;
	int mid=(low+high)/2;
	if(key==arr[mid])
		return mid;
	if(key>arr[mid])
		return binarysearch(arr,(mid+1),high,key);
	return binarysearch(arr,low,mid-1,key);
}
void del(int *arr,int *n,int key)
{
	int pos=binarysearch(arr,0,*n-1,key);
	if(pos==-1)
		return;
	while(pos < *n-1)
	{
		arr[pos]=arr[pos+1];
		pos++;
	}
	*n=*n-1;
}
/*void insert(int* arr,int *n,int val)
{
    int ind = 0;

    while(arr[ind]<=val)
        ind++;

    int* temp = new int[*n+1];

    for(int i=0;i<ind;i++)
        temp[i] = arr[i];

    temp[ind] = val;

    for(int i=ind+1;i<n+1;i++
        temp[i] = arr[i-1];

    delete(arr);

    arr = temp;

    *n++;
}*/
int main()
{
	int arr[]={1,2,3,4,5,6};
	int n=sizeof(arr)/sizeof(int);
	int key=1;
	printarr(arr,n);
	if(binarysearch(arr,0,5,key)==-1)
		printf("Not Found\n");
	else
		printf("Found at index %d\n",binarysearch(arr,0,5,key));
	del(arr,&n,key);
	printarr(arr,n);
	return 0;
}
