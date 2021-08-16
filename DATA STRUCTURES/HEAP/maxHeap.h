#include<bits/stdc++.h>
using namespace std;

void swap(int* x,int* y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

class maxHeap{

private:
    int* h = nullptr;
    int size = 0;
    int capacity = 0;

    int left(int i)
    {
        return 2*i + 1;
    }

    int right(int i)
    {
        return 2*i + 2;
    }

    int parent(int i)
    {
        return (i-1)/2;
    }

    void maxHeapify(int i)
    {
        int largest = i;

        if(left(i) < size && h[left(i)] > h[largest])
            largest = left(i);

        if(right(i) < size && h[right(i)] > h[largest])
            largest = right(i);

        if(largest == i)
            return;

        swap(h+largest,h+i);

        maxHeapify(largest);
    }

public:
    maxHeap()
    {

    }

    maxHeap(int c)
    {
        capacity = c;
        h = new int[c];
    }

    maxHeap(int arr[],int n)
    {
        capacity = n;
        size = n;
        h = arr;

        for(int i = n/2-1;i>=0;i--)
            maxHeapify(i);
    }

    void push(int x)
    {
        if(size < capacity)
        {
            h[size++] = x;

            int i = size-1;

            while(i && h[parent(i)] < h[i])
                swap(&h[i],&h[parent(i)]);
        }
    }

    int sz()
    {
        return size;
    }

    int top()
    {
        if(size)
            return h[0];

        return -1;
    }

    void pop()
    {
        if(size)
        {
            swap(h,h+size-1);

            size--;

            maxHeapify(0);
        }
    }
};
