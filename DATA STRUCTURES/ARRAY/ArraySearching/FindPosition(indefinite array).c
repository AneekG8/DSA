/*
FIND POSITION OF A NUMBER IN AN INFINITE ARRAY:

Let low be pointing to 1st element and high pointing to 2nd element of array, Now compare key with high index element,
->if it is greater than high index element then copy high index in low index and double the high index.
->if it is smaller, then apply binary search on high and low indices found.
*/
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
int findpos(int arr[], int key) 
{ 
    int l = 0, h = 1; 
    int val = arr[0]; 
  
    // Find h to do binary search 
    while (val < key) 
    { 
        l = h;        // store previous high 
        h = 2*h;      // double high index 
        val = arr[h]; // update new val 
    } 
  
    // at this point we have updated low and 
    // high indices, Thus use binary search  
    // between them 
    return binarysearch(arr, l, h, key); 
} 
int main()
{
	int arr[]={1,2,3,4,6,7,56,78,99,100,105,106};
	int key=106;
	if(findpos(arr,key)==-1)
		printf("Not Found\n");
	else
		printf("Found at index %d",findpos(arr,key));
	return 0;
}
