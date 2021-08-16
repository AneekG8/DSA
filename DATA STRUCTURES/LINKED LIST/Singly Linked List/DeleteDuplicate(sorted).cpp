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
void delDup1(Node *head_ref)			//without free()
{
	Node *curr=head_ref;
	Node *temp;
	while(temp!=NULL)
	{
		temp=curr->next;
		while(temp!=NULL && temp->data==curr->data )
		{
			temp=temp->next;
		}
		curr->next=temp;
		curr=curr->next;

	}
}
void delDup2(Node *head_ref)				//with free();
{
	Node *curr=head_ref;
	Node *temp;
	while(curr->next!=NULL)
	{
		if(curr->data==curr->next->data)
		{
			temp=curr->next->next;
			free(curr->next);
			curr->next=temp;
		}
		else{
			curr=curr->next;
		}
	}
}
void delDup3(Node *head_ref)				//recursive
{
	Node *temp;
	if(head_ref==NULL)
	{
		return;
	}
	if(head_ref->next!=NULL)
	{
		if(head_ref->data==head_ref->next->data)
		{
			temp=head_ref->next->next;
			free(head_ref->next);
			head_ref->next=temp;
			delDup3(head_ref);
		}
		else
		{
			delDup3(head_ref->next);
		}
	}
}

void delDup(Node* head)
{
    if(!head)
        return;

    Node* curr = head->next;

    while(curr && curr->data == head->data)
    {
        Node* next = curr->next;

        delete(curr);

        curr = next;
    }

    head->next = curr;

    delDup(curr);
}
int main()
{
	Node *head=NULL;
	pushFront(&head,11);
	pushFront(&head,11);
	pushFront(&head,11);
	pushFront(&head,21);
	pushFront(&head,43);
	pushFront(&head,43);
	pushFront(&head,60);
	pushFront(&head,60);
	printList(head);
	delDup(head);
	printList(head);
	return 0;
}
