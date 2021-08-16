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
int ceilSearch(int *arr,int low,int high,int x)
{
	int mid;

    /* If x is smaller than
       or equal to the first element,
       then return the first element */
    if(x <= arr[low])
        return low;

    /* If x is greater than the last element,
       then return -1 */
    if(x > arr[high])
        return -1;

    /* get the index of middle element of arr[low..high]*/
    mid = (low + high) / 2; /* low + (high - low)/2 */

    /* If x is same as middle element,
       then return mid */
    if(arr[mid] == x)
        return mid;

    /* If x is greater than arr[mid],
       then either arr[mid + 1] is ceiling of x
       or ceiling lies in arr[mid+1...high] */
    else if(arr[mid] < x)
    {
        if(mid + 1 <= high && x <= arr[mid + 1])
            return mid + 1;
        else
            return ceilSearch(arr, mid + 1, high, x);
    }

    /* If x is smaller than arr[mid],
       then either arr[mid] is ceiling of x
       or ceiling lies in arr[mid-1...high] */
    else
    {
        if(mid - 1 >= low && x > arr[mid - 1])
            return mid;
        else
            return ceilSearch(arr, low, mid - 1, x);
    }

}

int ceilSearch1(int arr[],int l,int r,int x)
{
    if(r >= l)
    {
        if(x <= arr[l])
            return l;

        if(x > arr[r])
            return -1;

        int mid = (l+r)/2;

        if(x == arr[mid])
            return mid;

        else if (arr[mid] > x)
            return (mid-1) >= l && arr[mid-1] >= x ? ceilSearch1(arr,l,mid-1,x) : mid;  //arr[mid-1]>=x implies mid is not the ceiling for sure

        else
            return ceilSearch1(arr,mid+1,r,x);
    }

    return -1;
}

int ceilSearchItr(int arr[],int n,int x)
{
    int l = 0, r = n-1;

    int res = -1;

    while(l<=r)
    {
        if(x <= arr[l])
            return l;

        if(x > arr[r])
            return res;

        int mid = (l+r)/2;

        if(arr[mid] == x)
            return mid;

        else if(x>arr[mid])
            l = mid+1;

        else
            res = mid,r = mid-1;
    }

    return res;
}
int main()
{
    int arr[] = {1, 2, 5,7,9,11,12, 19,20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 4;
    int index = ceilSearchItr(arr,n,x);
    if(index == -1)
        cout << "Ceiling of " << x
             << " doesn't exist in array ";
    else
        cout << "ceiling of " << x
             << " is " << arr[index];

    return 0;
}
