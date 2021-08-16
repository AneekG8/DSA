//find out the k most frequent elements from a given stream integers

#include<bits/stdc++.h>
using namespace std;

void kMostFrequent(int arr[],int n,int k)
{
    //store top elements
    vector<int> top(k+1);     //the last(extra) place keeps track of the newly read element

    //keep track of frequency
    unordered_map<int,int> freq;

    for(int i=0;i<n;i++)
    {
        freq[arr[i]]++;

        top[k]=arr[i];

        //find the first occurrence of arr[i] in top
        auto it=find(top.begin(),top.end()-1,arr[i]);

        //now in the top array compare all the elements before arr[i] to reposition it
        for(int j=distance(top.begin(),it)-1;j>=0;j--)
        {
            if(freq[top[j]] < freq[top[j+1]])
                swap(top[j],top[j+1]);

            else if(freq[top[j]] == freq[top[j+1]] && top[j]>top[j+1])
                swap(top[j],top[j+1]);

            else
                break;
        }

        //print the top k elements
        for(int i=0;i<k && top[i]!=0;i++)
            cout<<top[i]<<" ";

        cout<<endl;
    }
}
//time O(n*k)

int main()
{
    int k = 4;
    int arr[] = { 5, 2, 1, 3, 2 ,7,7,5,1,3,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    kMostFrequent(arr, n, k);
    return 0;
}
