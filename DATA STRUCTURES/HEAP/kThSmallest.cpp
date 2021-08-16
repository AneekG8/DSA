//given an array find the kTh smallest number

// A C++ program to find k'th smallest element using max heap
#include <climits>
#include <iostream>
using namespace std;

// Prototype of a utility function to swap two integers
void swap(int* x, int* y);

// A class for Max Heap
class MaxHeap {
	int* harr; // pointer to array of elements in heap
	int capacity; // maximum possible size of max heap
	int heap_size; // Current number of elements in max heap
public:
	MaxHeap(int a[], int size); // Constructor
	void maxHeapify(int i); // To maxHeapify subtree rooted with index i
	int parent(int i) { return (i - 1) / 2; }
	int left(int i) { return (2 * i + 1); }
	int right(int i) { return (2 * i + 2); }

	int extractMax(); // extracts root (maximum) element
	int getMax() { return harr[0]; } // Returns maximum

	// to replace root with new node x and heapify() new root
	void replaceMax(int x)
	{
		harr[0] = x;
		maxHeapify(0);
	}
};

MaxHeap::MaxHeap(int a[], int size)
{
	heap_size = size;
	harr = a; // store address of array
	int i = (heap_size - 1) / 2;
	while (i >= 0) {
		maxHeapify(i);
		i--;
	}
}

// Method to remove maximum element (or root) from max heap
int MaxHeap::extractMax()
{
	if (heap_size == 0)
		return INT_MAX;

	// Store the maximum vakue.
	int root = harr[0];

	// If there are more than 1 items, move the last item to root
	// and call heapify.
	if (heap_size > 1) {
		harr[0] = harr[heap_size - 1];
		maxHeapify(0);
	}
	heap_size--;

	return root;
}

// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::maxHeapify(int i)
{
	int l = left(i);
	int r = right(i);
	int largest = i;
	if (l < heap_size && harr[l] > harr[i])
		largest = l;
	if (r < heap_size && harr[r] > harr[largest])
		largest = r;
	if (largest != i) {
		swap(&harr[i], &harr[largest]);
		maxHeapify(largest);
	}
}

// A utility function to swap two elements
void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

//!method 1 using MinHeap extract min k times


//!method 2 using MaxHeap
// Function to return k'th largest element in a given array
int kThSmallest(int arr[], int n, int k)
{
    MaxHeap h(arr,k);

    for(int i=k;i<n;i++)
    {
        if(arr[i]<h.getMax())
        {
            h.replaceMax(arr[i]);
        }
    }

    return h.getMax();
}

//!method 3 : using quick select
int partition(int arr[],int l,int r)
{
    int ind = rand() % (r-l+1) + l;

    swap(arr+r,arr+ind);

    int i = -1;

    for(int j = 0;j<r;j++)
    {
        if(arr[j] < arr[r])
            swap(&arr[++i],&arr[j]);
    }

    swap(&arr[++i],&arr[r]);

    return i;
}

int kThSmallest(int arr[],int l,int r,int k)
{
    int p = partition(arr,l,r);

    if(p == k-l-1)
        return arr[p];

    if(p < k-l-1)
        return kThSmallest(arr,p+1,r,k-p+l-1);  //as we have seen p-l+1 up to pth index

    return kThSmallest(arr,l,p-1,k);
}

// Driver program to test above methods
int main()
{
	int arr[] = { 1,5,2,8,9,10,4,16,0,4,27,5};
	int n = sizeof(arr) / sizeof(arr[0]), k = 12;
	cout << "K'th smallest element is " << kThSmallest(arr, n, k);
	return 0;
}

