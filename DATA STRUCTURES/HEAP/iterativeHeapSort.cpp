//heapsort in iterative approach

#include<iostream>
using namespace std;


void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}



//iterative approach to build max heap from array
void buildMaxHeap(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i;

        //child > parent
        while(j!=0 && arr[j]>arr[(j-1)/2])
        {
            swap(&arr[j],&arr[(j-1)/2]);
            j=(j-1)/2;
        }
    }
}

//sorting function
void heapsortItr(int arr[],int n)
{
    //create a max heap
    buildMaxHeap(arr,n);

    //now use the heapify function to extract root
    for(int i=n-1;i>0;i--)  //to keep track of size of heap and count of the extraction
    {
        swap(&arr[0],&arr[i]);

        int j=0;

        while(j<i)    //i-1 will be the new last index as one element has already been extraced
        {
            int largest=j;

            int l=2*j+1;    //left child

            if(l<i && arr[l]>arr[largest])
                largest=l;

            int r=2*j+2;    //right child

            if(r<i && arr[r]>arr[largest])
                largest=r;

            if(largest!=j)
            {
                swap(&arr[largest],&arr[j]);
                j=largest;
            }
            else
                break;
        }
    }
}

void printArray(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;
}


int main()
{
    int arr[]={15,20,1,6,100,50,2,89,43,21,5,10,56};

    int n=sizeof(arr)/sizeof(int);

    //buildMaxHeap(arr,n);

    heapsortItr(arr,n);

    printArray(arr,n);

    return 0;
}
