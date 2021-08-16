//find median after merging two given sorted arrays of unequal sizes

#include<iostream>
using namespace std;

int getMedian(int arr1[],int n,int arr2[],int m)
{
    int count=0,i=0,j=0;

    int m1=-1,m2=-1;    //left and right median

    while(count<=(m+n)/2)
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

    if((m+n)%2)
        return m2;  //odd number of total terms

    return (m1+m2)/2;
}

int main()
{
    int A[] = {900};
    int B[] = {5, 8, 10, 20};

    int N = sizeof(A) / sizeof(A[0]);
    int M = sizeof(B) / sizeof(B[0]);

    printf("%d", getMedian( A, N, B, M ) );
    return 0;
}
