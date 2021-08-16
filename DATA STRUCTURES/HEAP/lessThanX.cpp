//given a binary heap and a value x print all the nodes lesser than x

#include<bits/stdc++.h>
using namespace std;

// Prototype of a utility function to swap two integers
template<typename T>
void swap(T* x,T* y)
{
    T temp=*x;
    *x=*y;
    *y=temp;
}

template<typename T,typename comp>
class MinHeap{
public:
    //array for the heap
    T* h;

    int capacity;
    int size;

    //heapifies a subtree with root at i
    //heapify function that assumes subtrees are already heap
    void MinHeapify(int i);  //from i we start to heapify(0 generally)

    //constructor
    MinHeap(int capacity)
    {
        this->capacity=capacity;

        h=new T[capacity];
        size=0;
    }

    //constructor   this is actually the heapify function for an input array
    MinHeap(T arr[],int n)
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

    bool isEmpty(){return size==0;}

    //insertion
    void insert(T x)
    {
        comp c;

        if(size<capacity)
        {
            h[size]=x;
            size++;

            //index of this new element
            int i=size-1;

            while(i!=0 && c.operator()(h[parent(i)],h[i]))
            {
                swap(&h[parent(i)],&h[i]);
                i=parent(i);
            }
        }
    }

    //get the minimum element
    T getMin(){return h[0];}

    //deletion/extract the minimum element
    T extractMin()
    {
            if(size==1)
            {
                size--;
                return h[0];
            }

            T root=h[0];

            h[0]=h[size-1];

            //store the root in last element for sorting
            h[size-1]=root;

            size--;

            MinHeapify(0);

            return root;
    }

    //decrease a value of a key to a new value
    /*void decreaseKey(int i,int x)
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
    }*/

    //deletion at i
    /*void Delete(int i)
    {
        if(size && i<size)
        {
            decreaseKey(i,INT_MIN);

            extractMin();
        }
    }*/
    friend void lessThanX(int x,int i=0);
};

template<typename T,typename comp>
void MinHeap<T,comp>::MinHeapify(int i)
{
    comp c;

    int smallest=i;

    if( left(i)<size && c.operator()(h[smallest],h[left(i)]) )
        smallest=left(i);

    if( right(i)<size && c.operator()(h[smallest],h[right(i)]) )
        smallest=right(i);

    if(smallest!=i)     //only case that the subtree with root at i is not a heap
    {
        swap(&h[smallest],&h[i]);

        MinHeapify(smallest);
    }
}

void lessThanX(MinHeap<int,greater<int>> heap,int x,int i=0)
{
    if(i<heap.size)
    {
        if(heap.h[i]>=x)
            return;
        cout<<heap.h[i]<<" ";

        lessThanX(heap,x,heap.left(i));
        lessThanX(heap,x,heap.right(i));
    }
}

int main()
{
    int arr[]={3,2,15,5,4,45,80,6,150,77,120};
    int n=sizeof(arr)/sizeof(int);

    MinHeap<int,greater<int>> h(arr,n);

    lessThanX(h,100);

    return 0;
}
