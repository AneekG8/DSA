#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node *next;
};
void pushFront(Node **head_ref,int val)					//pushes an element to the front of a list
{
	Node *new_node=new Node();
	new_node->data=val;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;
}
void printList(Node *head_ref)							//prints a list
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
void deleteList(Node **head_ref)						//delete the whole list
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
bool search(Node *head_ref,int key)					//returns true if key is present in the list , false otherwise
{
	if(head_ref==NULL)
		return false;
	if(head_ref->data==key)
		return true;
	else
		return search(head_ref->next,key);
}
int main()
{
	Node *head=NULL;
	pushFront(&head,3);
	pushFront(&head,4);
	pushFront(&head,5);
	pushFront(&head,6);
	printList(head);
	cout<<search(head,5)<<endl;
	deleteList(&head);
	printList(head);
	cout<<search(head,6)<<endl;
	return 0;

}
