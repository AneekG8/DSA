/*
segregate odd and even nodes in a list
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
void segregate(Node **head_ref)
{
	Node *even_start=NULL,*even_end=NULL,*odd_start=NULL,*odd_end=NULL;
	Node *curr=*head_ref;
	while(curr!=NULL)		//creating list of even nodes
	{
		if(curr->data%2==0)
		{
			if(even_start==NULL)	//initializing list of even nodes
			{
				even_start=curr;
				even_end=even_start;
			}
			else		//appending the even nodes
			{
				even_end->next=curr;
				even_end=even_end->next;
			}
		}
		else		//creating list of odd nodes
		{
			if(odd_start==NULL)	//initializing list of odd nodes
			{
				odd_start=curr;
				odd_end=odd_start;
			}
			else		//appending the odd nodes
			{
				odd_end->next=curr;
				odd_end=odd_end->next;
			}
		}
		curr=curr->next;
	}
	//changing the original list
	*head_ref=even_start;
	even_end->next=odd_start;
	odd_end->next=NULL;
}

void segregateList(Node* head)
{
    Node* i = nullptr;

    Node* j = head;

    while(j)
    {
        if(j->data % 2 == 0)
        {
            i = !i ? head : i->next;

            int t = i->data;

            i->data = j->data;

            j->data = t;
        }

        j = j->next;
    }
}
int main()
{
	Node *head=NULL;
	pushFront(&head,1);
	pushFront(&head,2);
	pushFront(&head,3);
	pushFront(&head,2);
	pushFront(&head,1);
	printList(head);
	segregateList(head);
	printList(head);
	return 0;
}
