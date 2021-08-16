/*
Given a sorted list delete the duplicate elements from it.
*/
#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};
void pushFront(Node **head_ref,int val)
{
	Node *new_node=new Node();
	new_node->data=val;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}
void printList(Node *head_ref)
{
	while(head_ref!=NULL)
	{
		cout<<head_ref->data<<" ";
		head_ref=head_ref->next;
	}
	cout<<endl;
}
void swap(Node **head_ref,int x,int y)
{
	Node *currx=*head_ref,*curry=*head_ref,*prevx=NULL,*prevy=NULL;
	while(currx && currx->data!=x)
	{
		prevx=currx;
		currx=currx->next;
	}
	while(curry && curry->data!=y)
	{
		prevy=curry;
		curry=curry->next;
	}
	if(*head_ref==NULL || !currx || !curry)
	{
		cout<<"empty or doesn't exist"<<endl;
		return;
	}
	if(prevx!=NULL)
	{
		prevx->next=curry;
	}
	else
	{
		*head_ref=curry;
	}
	if(prevy!=NULL)
	{
		prevy->next=currx;
	}
	else
	{
		*head_ref==currx;
	}
	Node *temp=curry->next;
	curry->next=currx->next;
	currx->next=temp;
}
int main()
{
	Node *head=NULL;
	pushFront(&head,6);
	pushFront(&head,5);
	pushFront(&head,4);
	pushFront(&head,3);
	pushFront(&head,2);
	pushFront(&head,1);
	printList(head);
	swap(&head,1,6);
	printList(head);
	return 0;
}
