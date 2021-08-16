#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};
class CIRQ{
	public:
		Node *front=NULL;
		Node *rear=NULL;
		int Front()
		{
			if(front==NULL)
			{
				//cout<<"list is empty"<<endl;
				return -1;
			}
			return front->data;
		}
		int Rear()
		{
			if(front==NULL)
			{
				//cout<<"list is empty"<<endl;
				return -1;
			}
			return rear->data;
		}
		void enqueue(int val)
		{
			Node *new_node=new Node();
			new_node->data=val;
			new_node->next=front;
			if(front==NULL)
			{
				front=new_node;
			}
			else
			{
				rear->next=new_node;
			}
			rear=new_node;
		}
		void dequeue()
		{
			if(front==NULL)
			{
				cout<<"queue is empty"<<endl;
				return;
			}
			if(front==rear)		//single element
			{
				front=NULL;
				rear=NULL;
				return;
			}
			Node *temp=front;
			front=front->next;
			rear->next=front;
			free(temp);
		}
		void display()
		{
			if(front==NULL)
			{
				cout<<"list is empty"<<endl;
				return;
			}
			Node *temp=front;
			do
			{
				cout<<temp->data<<" ";
				temp=temp->next;
			}while(temp!=front);
			cout<<endl;
		}
};
int main()
{
	CIRQ q;
	q.enqueue(10);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	cout<<q.Front()<<endl;
	cout<<q.Rear()<<endl;
	q.display();
	//10 30 40 50
	q.dequeue();
	cout<<q.Front()<<endl;
	cout<<q.Rear()<<endl;
	q.display();
	//30 40 50
	q.dequeue();
	cout<<q.Front()<<endl;
	cout<<q.Rear()<<endl;
	q.display();
	//40 50
	q.dequeue();
	cout<<q.Front()<<endl;
	cout<<q.Rear()<<endl;
	q.display();
	//50
	q.dequeue();
	cout<<q.Front()<<endl;
	cout<<q.Rear()<<endl;
	q.display();
	//NULL
}
