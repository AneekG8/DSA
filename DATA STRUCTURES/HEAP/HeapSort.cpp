//given an array sort it using heapsort

// A C++ program to demonstrate common Binary Heap Operations
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

    //heapifies a subtree with root at i
    //!heapify function that assumes subtrees are already heap
    void MinHeapify(int i);  //takes O(logn) as subtrees are already heap

public:

    //constructor
    MinHeap(int capacity)
    {
        this->capacity=capacity;

        h=new int[capacity];
        size=0;
    }

    //!constructor   NOTE:- this is actually the heapify function for an input array
    //takes O(n) time analytically
    MinHeap(int arr[],int n)
    {
        this->h=arr;

        capacity=size=n;

        //heapify every subtree from end
        for(int i=n/2-1;i>=0;i--)
            MinHeapify(i);  //take O(logn) time but the whole loop takes O(n)
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

            MinHeapify(0);     //O(logn)

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


//descending order sorting using MinHeap

void heapsort(int arr[],int n)
{
    MinHeap h(arr,n);   //heapifies the array takes O(n) time

    //now extract element one by one
    for(int i=0;i<n-1;i++)
    {
        h.extractMin();     //stores the elements at the end of the array
    }

    //each heapify inside the extract function takes O(logn) time
    //so the whole loop takes O(nlogn) time
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}


int main()
{
    int arr[]={4,10,3,5,1};

    heapsort(arr,5);

    printArray(arr,5);

    return 0;
}
