#include<iostream>
using namespace std;

class Deque{

private:
    int *arr;
    int front;
    int rear;
    int size;
    int capacity;
public:
    Deque()
    {
        capacity=5;
        arr=new int[capacity];
        front=0;
        rear=-1;
        size=0;
    }

    Deque(int n)
    {
        capacity=n;
        arr=new int[capacity];
        front=0;
        rear=-1;
        size=0;
    }

    bool isFull()
    {
        return size==capacity;
    }

    bool isEmpty()
    {
        return size==0;
    }

    void insertFront(int x)
    {
        if(isFull())
            return;
        front--;
        if(front==-1)
            front=capacity-1;
        arr[front]=x;
        size++;
    }

    void insertBack(int x)
    {
        if(isFull())
            return;
        rear++;
        if(rear==capacity)
            rear=0;
        arr[rear]=x;
        size++;
    }

    void deleteFront()
    {
        if(isEmpty())
            return;
        front++;
        if(front==capacity)
            front=0;
        size--;
    }

    void deleteBack()
    {
        if(isEmpty())
            return;
        rear--;
        if(rear==-1)
            rear=capacity-1;
        size--;
    }

    void display()
    {
        int count=size;
        int i=front;
        while(count--)
        {
            cout<<arr[i]<<" ";
            i++;
            if(i==capacity)
                i=0;
        }
        cout<<endl;
    }
};

int main()
{
    Deque dq;
    dq.insertBack(1);
    dq.insertFront(5);
    dq.insertBack(2);
    dq.insertFront(4);
    dq.insertBack(3);

    dq.insertBack(8);

    dq.deleteFront();
    dq.deleteFront();
    dq.deleteFront();

    dq.insertBack(2);
    dq.insertFront(4);
    dq.insertBack(3);

    dq.deleteBack();
    dq.deleteFront();

    dq.display();
    return 0;

}
