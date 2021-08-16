//given an array sort it using index mapping hash

#include<bits/stdc++.h>
using namespace std;


void hashSort(int arr[],int n)
{
    //we use two different arrays for positive and negative numbers

    //also size of mapping arrays depend on the max number to be stored in them

    int max=*std::max_element(arr,arr+n);

    int min=abs(*std::min_element(arr,arr+n));  //this will be used as index so abs

    //these arrays are used to map counts of numbers in array to index of these arrays
    int posmap[max+1]={0};

    int negmap[min+1]={0};

    //store counts
    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
            negmap[abs(arr[i])]++;
        else
            posmap[arr[i]]++;
    }

    //modify the actual array
    int index=0;

    //first comes negative map from backwards
    for(int i=min;i>=0;i--)
    {
        if(negmap[i])   //value is i
        {
            for(int c=0;c<negmap[i];c++)    //count of i
            {
                arr[index]=(-1)*i;
                index++;
            }
        }
    }

    for(int i=0;i<=max;i++)
    {
        if(posmap[i])   //value is i
        {
            for(int c=0;c<posmap[i];c++)    //count of i
            {
                arr[index]=i;
                index++;
            }
        }
    }
}

int main()
{
    int a[] = { -1, -2, -3,-5, -4, -1,-5, -6, 8, 7,
                        5, 4, 0,3, 2, 1, 0,8 };
    int n = sizeof(a) / sizeof(a[0]);
    hashSort(a, n);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    return 0;
}
