#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};
class CLL{
	public:
		Node *head_ref=NULL;
		void pushFront(int val)
		{
			Node *new_node=new Node();
			Node *temp=head_ref;
			new_node->data=val;
			if(head_ref!=NULL)
			{
				new_node->next=(head_ref);
				while(temp->next!=head_ref)
				{
					temp=temp->next;
				}
				temp->next=new_node;
			}
			else
			{
				new_node->next=new_node;
			}
			head_ref=new_node;
		}
		void append(int val)
		{
			Node *new_node=new Node();
			new_node->data=val;
			if(head_ref==NULL)
			{
				head_ref=new_node;
			}
			else
			{
				Node *temp=head_ref;
				while(temp->next!=head_ref)
				{
					temp=temp->next;
				}
				temp->next=new_node;
			}
			new_node->next=head_ref;
		}
		void addAfter(int val,int key)
		{
			if(head_ref==NULL)
			{
				return;
			}
			Node *new_node=new Node();
			new_node->data=val;
			Node *temp=head_ref;
			while(temp->next!=head_ref && temp->data!=key)
			{
				temp=temp->next;
			}
			if(temp->next==head_ref && temp->data!=key)
			{
				cout<<key<<" doesn't exist in the key"<<endl;
				return;
			}
			new_node->next=temp->next;
			temp->next=new_node;
		}
		void Delete(int key)
		{
			if(head_ref==NULL)
			{
				cout<<"list is empty"<<endl;
				return;
			}
			if(head_ref->data==key && head_ref->next==head_ref)	//head is the only node in the list and it is the key as well
			{
				head_ref=NULL;
				return;
			}
			Node *last=head_ref;		//tail node of the list
			while(last->next!=head_ref)
			{
				last=last->next;
			}
			Node *prev=last;
			Node *temp=head_ref;
			while(temp->next!=head_ref && temp->data!=key)
			{
				prev=temp;
				temp=temp->next;
			}
			if(temp->next==head_ref && temp->data!=key)		//key isn't in the list
			{
				cout<<"key doesn't exist in the list"<<endl;
				return;
			}
			if(temp==head_ref)		//if head is the key change the head 
			{
				head_ref=head_ref->next;
			}
			prev->next=temp->next;
			free(temp);
		}
		void printList()
		{
			if(head_ref==NULL)
			{
				cout<<"list is empty"<<endl;
				return;
			}
			Node *temp=head_ref;
			do{
				cout<<temp->data<<" ";
				temp=temp->next;
			}while(temp!=head_ref);
			cout<<endl;
		}
};
int main()
{
	CLL list;
	list.pushFront(5);
	list.printList();
	list.Delete(5);
	list.printList();
	list.pushFront(10);
	list.append(20);
	list.append(30);
	list.addAfter(2,10);
	list.addAfter(40,30);
	list.addAfter(25,100);
	list.printList();
	list.Delete(20);
	list.printList();
	list.Delete(10);
	list.printList();
	list.Delete(40);
	list.printList();
	return 0;
}
