//Implement a double ended queue
#include<bits/stdc++.h>
#define size 5
using namespace std;
class Dequeue{
	public:
		int arr[size];
		int front=0,rear=-1,count=0;
		//utiliy functions
		bool isEmpty(){
			return count==0;
		}
		bool isFull(){
			return count==size;
		}
		//operations
		int getFront(){
			return arr[front];
		}
		int getRear(){
			return arr[rear];
		}
		//insertion operations
		void insertFront(int val)
		{
			if(!isFull())
			{
				front--;
				if(front==-1)
				{
					front=size-1;
				}
				arr[front]=val;
				count++;
			}
			else
			{
				cout<<"queue is full"<<endl;
			}
		}
		void insertRear(int val){
			if(!isFull())
			{
				rear=((rear+1)%size);
				arr[rear]=val;
				count++;
			}
			else
			{
				cout<<"queue is full"<<endl;
			}
		}
		//deletion operations
		void deleteFront(){
			if(!isEmpty())
			{
				front=((front+1)%size);
				count--;
			}
			else
			{
				cout<<"queue is empty"<<endl;
			}
		}
		void deleteRear(){
			if(!isEmpty())
			{
				rear--;
				if(rear==-1)
				{
					rear=size-1;
				}
				count--;
			}
			else
			{
				cout<<"queue is empty"<<endl;
			}
		}
		//display operation
		void display(){
			if(isEmpty())
			{
				cout<<"queue is empty"<<endl;
				return;
			}
			int index=front,c=count;
			while(c--)
			{
				cout<<arr[index]<<" ";
				index++;
				if(index==size)
				{
					index=0;
				}
			}
			cout<<endl;
		} 
};
int main()
{
	Dequeue q;
	q.insertRear(1);
	q.deleteFront();
	q.insertRear(2);
	q.insertRear(3);
	q.insertRear(4);
	q.insertRear(5);
	q.deleteFront();
	q.insertRear(6);
	q.display();
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	q.insertFront(2);
	q.display();
	q.insertFront(1);
	q.display();
	q.deleteFront();
	q.display();
	q.insertFront(2);
	q.display();
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	q.deleteRear();
	q.display();
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	q.insertFront(6);
	q.display();
	cout<<q.getFront()<<endl;
	cout<<q.getRear()<<endl;
	return 0; 
}
