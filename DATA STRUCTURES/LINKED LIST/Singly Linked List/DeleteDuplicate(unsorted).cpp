/*
Given a unsorted list delete the duplicate elements from it.
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
void delDup(Node *head_ref)
{
	while(head_ref!=NULL)
	{
		Node *curr=head_ref->next;
		Node *prev=head_ref;
		while(curr!=NULL)
		{
			if(curr->data==head_ref->data)
			{
				prev->next=curr->next;
				free(curr);
				curr=prev->next;
			}
			else
			{
				curr=curr->next;
				prev=prev->next;
			}
		}
		head_ref=head_ref->next;
	}
}

//deletes all nodes from a list when given a key
Node* deleteAll(Node* head,int key)
{
    if(!head)
        return nullptr;

    head->next = deleteAll(head->next,key);

    if(head->data == key)
    {
        Node* next = head->next;

        delete(head);

        head = next;
    }

    return head;
}

//deletes a single node and return the next node
Node* deleteNode(Node* node)
{
    if(!node)
        return nullptr;

    Node* next = node->next;

    delete(node);

    return next;
}

void delDupNew(Node* head)
{
    Node* curr = head;

    while(curr)
    {
        curr->next = deleteAll(curr->next,curr->data);
        curr = curr->next;
    }
}
int main()
{
	Node *head=NULL;
	pushFront(&head,11);
	pushFront(&head,11);
	pushFront(&head,16);
	pushFront(&head,11);
	pushFront(&head,21);
	pushFront(&head,43);
	pushFront(&head,21);
	pushFront(&head,60);
	pushFront(&head,11);
	printList(head);
	delDupNew(head);
	printList(head);
	return 0;
}
