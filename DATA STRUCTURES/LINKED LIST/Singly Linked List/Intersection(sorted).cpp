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
Node *sortedIntersection(Node *a,Node *b)
{
	if(a==NULL || b==NULL)
	{
		return NULL;
	}
	if(a->data<b->data)
	{
		return sortedIntersection(a->next,b);
	}
	if(a->data > b->data)
	{
		return sortedIntersection(a,b->next);
	}
	Node *temp=new Node();
	temp->data=a->data;
	temp->next=sortedIntersection(a->next,b->next);
	return temp;
}


int main()
{
	Node *a=NULL;
	Node *b=NULL;
	Node *intersect=NULL;
	pushFront(&a,6);
	pushFront(&a,5);
	pushFront(&a,3);
	pushFront(&a,2);
	pushFront(&a,1);
	pushFront(&b,10);
	pushFront(&b,8);
	pushFront(&b,6);
	pushFront(&b,4);
	pushFront(&b,2);
	intersect=sortedIntersection(a,b);
	printList(intersect);
	return 0;
}
