//find the kTh largest elements in an array

#include<iostream>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int *x, int *y);

class MinHeap{
    //array for the heap
    int *h;
    int capacity;
    int size;

public:
    //heapifies a subtree with root at i
    //heapify function that assumes subtrees are already heap
    void MinHeapify(int i);  //from i we start to heapify(0 generally)

    //constructor
    MinHeap(int capacity)
    {
        this->capacity=capacity;

        h=new int[capacity];
        size=0;
    }

    //constructor   this is actually the heapify function for an input array
    MinHeap(int arr[],int n)
    {
        this->h=arr;

        capacity=size=n;

        //heapify every subtree from end
        for(int i=n/2-1;i>=0;i--)
            MinHeapify(i);
    }

    //index of left child
    int left(int i){return 2*i+1;}

    //index of right child
    int right(int i){return 2*i+2;}

    //index of parent
    int parent(int i){return (i-1)/2;}

    //insertion
    void insert(int x)
    {
        if(size<capacity)
        {
            h[size]=x;
            size++;

            //index of this new element
            int i=size-1;

            while(i!=0 && h[parent(i)]>h[i])
            {
                swap(&h[parent(i)],&h[i]);
                i=parent(i);
            }
        }
    }

    //get the minimum element
    int getMin(){return h[0];}

    //deletion/extract the minimum element
    int extractMin()
    {
        if(size)
        {
            if(size==1)
            {
                size--;
                return h[0];
            }

            int root=h[0];

            h[0]=h[size-1];

            //store the root in last element for sorting
            h[size-1]=root;

            size--;

            MinHeapify(0);

            return root;
        }

        return INT_MAX;
    }

    //decrease a value of a key to a new value
    void decreaseKey(int i,int x)
    {
        if(size)
        {
            h[i]=x;

            while(i!=0 && h[parent(i)]>h[i])
            {
                swap(&h[parent(i)],&h[i]);
                i=parent(i);
            }
        }
    }

    //deletion at i
    void Delete(int i)
    {
        if(size && i<size)
        {
            decreaseKey(i,INT_MIN);

            extractMin();
        }
    }
};

void MinHeap::MinHeapify(int i)
{
    int smallest=i;

    if(left(i)<size && h[left(i)]<h[smallest])
        smallest=left(i);

    if(right(i)<size && h[right(i)]<h[smallest])
        smallest=right(i);

    if(smallest!=i)     //only case that the subtree with root at i is not a heap
    {
        swap(&h[smallest],&h[i]);

        MinHeapify(smallest);
    }
}

void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

//!method using MinHeap

//build heap with first k elements of the array || O(k)

//now for the next n-k elements of the array
//if any element is greater than the root of heap swap and keep heap pattern
//thus we eliminate the lowest of the current k+1  elements(k in heap and one in from rest)
//takes O((n-k)*logk) time

//at last if sorted order is needed we need to extract from heap || O(klogk)

void kThLargestElements(int arr[],int n,int k)
{
    MinHeap h(arr,k);

    for(int i=k;i<n;i++)
    {
        if(arr[i]>h.getMin())
        {
            arr[0]=arr[i];
            h.MinHeapify(0);
        }
    }

    for(int i=0;i<k;i++)
    {
        cout<<h.getMin()<<" ";

        h.extractMin();
    }
}

int main()
{
    int arr[] = { 11, 3, 2, 1, 15, 5, 4,
                           45, 88, 96, 50, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);

    // Size of Min Heap
    int k = 5;

    kThLargestElements(arr,size,k);

    return 0;
}
