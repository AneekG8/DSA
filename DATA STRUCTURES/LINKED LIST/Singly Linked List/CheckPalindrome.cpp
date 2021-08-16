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
bool isPalindrome(Node *head_ref)
{
	Node* h = head_ref;

	int c = 0;

	while(h)
        c++,h=h->next;

    stack<int> s;

    for(int i=0;i<c/2;i++)
        s.push(head_ref->data),head_ref=head_ref->next;

    if(c%2)
        head_ref = head_ref->next;

    while(head_ref)
    {
        if(s.top() != head_ref->data)
            return false;

        s.pop();

        head_ref = head_ref->next;
    }

    return true;
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
	cout<<isPalindrome(head)<<endl;
	return 0;
}
