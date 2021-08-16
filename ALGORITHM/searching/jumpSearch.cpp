//JUMP SEARCH ALGO

//check in a specified range if satisfied linear search in that block

//time : ((n/m) + (m-1))    m being the size of jump

//best step size is sqrt(n)

#include<iostream>
#include<cmath>
using namespace std;


int jumpSearch(int arr[],int n,int x)
{
    int step = sqrt(n);

    int first = 0;  //first of each block

    while(arr[min((first+step),n)-1] < x)   //keep going forward
    {
        first += step;  //first of next block

        if(first >= n)
            return -1;
    }

    for(int i=first; i< first+step; i++)
        if(arr[i] == x) return i;   //can be optimize using double pointer technique

    return -1;
}

int main()
{
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21,
                34, 55, 89, 144, 233, 377, 610 };
    int x = 89;
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find the index of 'x' using Jump Search
    int index = jumpSearch(arr, n, x);

    // Print the index where 'x' is located
    cout << "\nNumber " << x << " is at index " << index;
    return 0;
}
