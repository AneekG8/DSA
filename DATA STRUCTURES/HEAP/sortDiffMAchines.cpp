/*
Given N machines. Each machine contains some numbers in sorted form.
But the amount of numbers, each machine has is not fixed.
Output the numbers from all the machine in sorted non-decreasing form.
*/

//as numbers from each machine is in a DLL from create a heap accordingly

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Prototype of a utility function to swap two integers
template<typename T>
void swap(T* x,T* y)
{
    T temp=*x;
    *x=*y;
    *y=temp;
}

class Node{

public:
    int data;
    Node* next;
};

class customComp{

public:
    bool operator()(Node* x,Node* y)
    {
        return x->data>y->data;
    }
};

/* Given a reference (pointer to pointer)
to the head of a list and an int, inserts
a new node on the front of the list. */
void push(Node** head_ref, int new_data)
{
	/* 1. allocate node */
	Node* new_node = new Node();

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. Make next of new node as head */
	new_node->next = (*head_ref);

	/* 4. move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Given a node prev_node, insert a new node after the given
prev_node */
void insertAfter(Node* prev_node, int new_data)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL)
	{
		cout<<"the given previous node cannot be NULL";
		return;
	}

	/* 2. allocate new node */
	Node* new_node = new Node();

	/* 3. put in the data */
	new_node->data = new_data;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. move the next of prev_node as new_node */
	prev_node->next = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a list and an int, appends a new node at the end */
void append(Node** head_ref, int new_data)
{
	/* 1. allocate node */
	Node* new_node = new Node();

	Node *last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. This new node is going to be
	the last node, so make next of
	it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty,
	then make the new node as head */
	if (*head_ref == NULL)
	{
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;
	return;
}

// This function prints contents of
// linked list starting from head
void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<" "<<node->data;
		node = node->next;
	}
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


Node* sortMachine(Node* v[],int size)
{
    Node* head=nullptr;

    //heapify with all heads
    MinHeap<Node*,customComp> h(v,size);


    while(!h.isEmpty())
    {
        Node* curr=h.extractMin();

        append(&head,curr->data);

        if(curr->next)
            h.insert(curr->next);
    }

    return head;
}


int main()
{
    Node* v[3]={nullptr};

    append(&(v[0]),30);
    append(&v[0],40);
    append(&v[0],60);
    append(&v[0],75);

    append(&(v[1]),35);
    append(&v[1],55);
    append(&v[1],80);

    append(&v[2],20);
    append(&v[2],25);
    append(&v[2],45);
    append(&v[2],70);

    Node* head=sortMachine(v,3);

    printList(head);

    return 0;
}
