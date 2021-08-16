/*
Given a list swap the elements pairwise.
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
void swapPair(Node **head_ref)					//swaps nodes pairwise
{
	Node *prev=NULL,*first=*head_ref,*second=(*head_ref)->next;
	if(!*head_ref || !(*head_ref)->next)
	{
		return;
	}
	while(first && second)			//for even nodes:- first will be null || for odd nodes:- second will be null first will not
	{
		if(!prev)
		{
			*head_ref=second;		//to change head(first pair)
		}
		else
		{
			prev->next=second;		//rest of the heads
		}
		first->next=second->next;	//link for swapping
		second->next=first;			//link for swapping
		prev=first;					//increment prev------------first now comes to end of the pair(as it switches place with second)
		first=first->next;			//increment first------------first now comes to end of the pair(as it switches place with second)
		if(first)					//we can increment second only if first is not null
			second=first->next;		//increment second------------first now comes to end of the pair(as it switches place with second)
	}
}
int main()
{
	Node *head=NULL;
	pushFront(&head,7);
	pushFront(&head,6);
	pushFront(&head,5);
	pushFront(&head,4);
	pushFront(&head,3);
	pushFront(&head,2);
	pushFront(&head,1);
	printList(head);
	swapPair(&head);
	printList(head);
	return 0;
}
