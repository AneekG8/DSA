// https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1

#include<bits/stdc++.h>
using namespace std;

class Item{

public:
    int value;
    int weight;
};

    bool cmp(Item a,Item b)
    {
        return ((double)a.value/(double)a.weight) > ((double)b.value/(double)b.weight);
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here

        sort(arr,arr+n,cmp);

        double maxVal = 0;

        for(int i=0;i<n;i++)
        {
            if(!W)
                break;

            int w = min(W,arr[i].weight);

            maxVal += (double)((double)(w*arr[i].value)/(double)arr[i].weight);

            W -= w;
        }

        return maxVal;
    }

    int main()
    {
        Item arr[] = {{60,10},{100,20},{120,30}};

        int W = 50;

        int n = sizeof(arr)/sizeof(int);

        double val = fractionalKnapsack(W,arr,n);

        cout<<val;

    }
