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
int detectAndCountLoop(Node *head_ref)
{
	if(head_ref==NULL || head_ref->next==NULL)
	{
		return 0;
	}
	Node *slow_p,*fast_p;
	slow_p=fast_p=head_ref;
	while(slow_p && fast_p && fast_p->next)
	{
		slow_p=slow_p->next;
		fast_p=fast_p->next->next;
		if(slow_p==fast_p)
		{
			int count=1;
			do
			{
				slow_p=slow_p->next;
				count++;
			}while(slow_p->next!=fast_p);
			return count;
		}
	}
	return 0;
}

int countLoop(Node* head)
{
    Node* slow = head, *fast = head;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast)
            break;
    }

    if(!fast || !(fast->next))
        return 0;

    int c = 0;

    do{
        c++;
        slow = slow->next;
    }while(slow != fast);

    return c;
}
int main()
{
	Node *head=NULL;
	pushFront(&head,3);
	pushFront(&head,4);
	pushFront(&head,5);
	pushFront(&head,6);
	printList(head);
	head->next->next->next->next=head->next;		//created loop between 5,4,3
	//printList(head);
	cout<<"length of loop: "<<countLoop(head)<<endl;
	return 0;
}
