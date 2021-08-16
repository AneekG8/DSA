#include<bits/stdc++.h>

using namespace std;

void printArray(int arr[],int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}


void radixSort(int arr[],int n)
{
    int max=*max_element(arr,arr+n);

    int d=0;

    //get no. of digits of max
    while(max)
    {
        d++;
        max/=10;
    }

    vector<list<int>> aux(10);

    for(int p=0;p<d;p++)
    {
        int exp = pow(10,p);

        for(int i=0;i<n;i++)
        {
            int ind=(arr[i]/exp)%10;

            aux[ind].push_back(arr[i]);
        }

        int i=0,j=0;
        while(i<n)
        {
            if(!aux[j].empty())
                arr[i]=aux[j].front(),aux[j].pop_front(),i++;
            else
                j++;
        }
    }
}

int main()
{
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66,1000,0 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    radixSort(arr, n);
    printArray(arr, n);
    return 0;
}
