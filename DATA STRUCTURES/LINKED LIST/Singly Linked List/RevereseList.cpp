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
void reverseList(Node **head_ref)
{
	Node *prev=NULL,*curr=*head_ref,*nex=curr->next;
	if(curr==NULL)
	{
		return;
	}
	while(nex!=NULL)
	{
		curr->next=prev;
		prev=curr;
		curr=nex;
		nex=nex->next;
	}
	curr->next=prev;
	*head_ref=curr;
}

void reverseList1(Node** head)
{
    Node* curr = *head, *prev = nullptr;
    while(curr)
    {
        Node* next = curr->next;

        curr->next = prev;

        prev = curr;

        curr = next;

        if(curr)
            *head = curr;
    }
}
int main()
{
	Node *head=NULL;
	pushFront(&head,1);
	pushFront(&head,2);
	pushFront(&head,3);
	pushFront(&head,4);
	pushFront(&head,5);
	printList(head);
	reverseList1(&head);
	printList(head);
	return 0;
}
