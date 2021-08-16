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
void pop(Node **head_ref,int key)
{
	Node *prev_node,*curr_node=(*head_ref);
	if((*head_ref)==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	while(curr_node!=NULL && curr_node->data!=key)
	{
		prev_node=curr_node;
		curr_node=curr_node->next;
	}
	if(curr_node==NULL)
	{
		cout<<key<<" doesn't exist in the list"<<endl;
		return;
	}
	else if(curr_node==(*head_ref))
	{
		(*head_ref)=(*head_ref)->next;
		free(curr_node);
		return;
	}
	prev_node->next=curr_node->next;
	free(curr_node);
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
int main()
{
	Node *head=NULL;
	pushFront(&head,3);
	pushFront(&head,4);
	pushFront(&head,5);
	pushFront(&head,6);
	pushFront(&head,6);
	printList(head);
	pop(&head,6);
	printList(head);
	return 0;
}
