//find median after merging two given sorted arrays each of size n

#include<iostream>
using namespace std;


//method 1: MERGING  ||  O(n)

//median will be average of n-1 and n indexed elements
//so to find the median we have to process at least n+1 elements

int getMedian(int arr1[],int arr2[],int n)
{
    int count=0,i=0,j=0;

    int m1=-1,m2=-1;    //left and right median

    while(count<=n)
    {
        if(arr1[i]<=arr2[j])
        {
            m1=m2;
            m2=arr1[i];
            i++;
        }
        else
        {
            m1=m2;
            m2=arr2[j];
            j++;
        }
        count++;
    }

    return (m1+m2)/2;
}


//method 2: divide and conquer || O(logn)


int median(int arr[],int n)
{
    if(n%2==0)
        return (arr[n/2]+arr[n/2-1])/2;

    return arr[n/2];
}


int getMedian2(int arr1[],int arr2[],int n)
{
    if(n==2)
        return (max(arr1[0],arr2[0])+min(arr1[1],arr2[1]))/2;

    int m1=median(arr1,n);
    int m2=median(arr2,n);

    if(m1==m2)
        return m1;

    if(m1<m2)
    {
        if(n%2==0)
            return getMedian2(arr1+n/2,arr2,n/2);

        return getMedian2(arr1+n/2,arr2,n/2+1);
    }

    else
    {
        if(n%2==0)
            return getMedian2(arr1,arr2+n/2,n/2);

        return getMedian2(arr1,arr2+n/2,n/2+1);
    }
}


int main()
{
    int ar1[] = {4,6,8,10,12};
    int ar2[] = {1,2,3,6,8};

    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is "
             << getMedian2(ar1, ar2, n1) ;
    else
        cout << "Doesn't work for arrays"
             << " of unequal size" ;
    return 0;
}
