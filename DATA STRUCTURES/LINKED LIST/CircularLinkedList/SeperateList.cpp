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
	Node *temp=*head_ref;
	new_node->data=val;
	if(*head_ref!=NULL)
	{
		new_node->next=(*head_ref);
		while(temp->next!=*head_ref)
		{
			temp=temp->next;
		}
		temp->next=new_node;
	}
	else
	{
		new_node->next=new_node;
	}
	*head_ref=new_node;
}
void printList(Node *head_ref)
{
	Node *temp=head_ref;
	do{
		cout<<temp->data<<" ";
		temp=temp->next;
	}while(temp!=head_ref);
	cout<<endl;
}
Node* getMid(Node *head_ref)
{
	Node *slow=head_ref,*fast=head_ref;
	while(fast->next!=head_ref && fast->next->next!=head_ref)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}
void splitList(Node *head_ref,Node **head_part1,Node **head_part2)
{
	Node *mid=getMid(head_ref);
	*head_part1=head_ref;
	*head_part2=mid->next;
	mid->next=*head_part1;
	Node *temp=*head_part2;
	while(temp->next!=head_ref)
	{
		temp=temp->next;
	}
	temp->next=*head_part2;
}
int main()
{
	Node *head=NULL;
	Node *head_part1=NULL;
	Node *head_part2=NULL;
	pushFront(&head,1);
	pushFront(&head,2);
	pushFront(&head,3);
	pushFront(&head,4);
	pushFront(&head,5);
	printList(head);
	splitList(head,&head_part1,&head_part2);
	printList(head_part1);
	printList(head_part2);
	return 0;
}
