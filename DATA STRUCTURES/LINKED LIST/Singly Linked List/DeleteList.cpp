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
	if(head_ref==NULL)
	{
		cout<<"List is empty"<<endl;
		return;
	}
	while(head_ref!=NULL)
	{
		cout<<head_ref->data<<" ";
		head_ref=head_ref->next;
	}
	cout<<endl;
}
void deleteList(Node **head_ref)
{
	Node *next_node,*curr_node=*head_ref;
	while(curr_node!=NULL)
	{
		next_node=curr_node->next;
		free(curr_node);
		curr_node=next_node;
	}
	*head_ref=NULL;
}
int main()
{
	Node *head=NULL;
	pushFront(&head,3);
	pushFront(&head,4);
	pushFront(&head,5);
	pushFront(&head,6);
	printList(head);
	deleteList(&head);
	printList(head);
	return 0;

}
