//insert a node a to a sorted list
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
void insertSorted(Node **head_ref,int val)
{
	if(*head_ref==NULL || val<(*head_ref)->data)
	{
		pushFront(head_ref,val);
		return;
	}
	Node *new_node=new Node();
	new_node->data=val;
	Node *prev,*curr=*head_ref;
	while(val>curr->data && curr->next!=*head_ref)
	{
		prev=curr;
		curr=curr->next;
	}
	if(curr->next!=*head_ref)
	{
		prev->next=new_node;
		new_node->next=curr;
		return;
	}
	curr->next=new_node;
	new_node->next=*head_ref;
}

/*void insertSorted1(Node** head_ref,int val)
{
    if(!(*head_ref) || val < (*head_ref)->data)
    {
        Node* node;
        node->data = val;
        node->next = *head_ref ? *head_ref : node;
        if(head_ref)
        {
            Node* last = *head_ref;

            do{
                last = last->next;
            }while(last != *head_ref);

            last->next = node;
        }
        *head_ref = node;

    }

    else
    {
        Node* prev = *head_ref, *curr = prev->next;

        do{
            prev = curr;
            curr = curr->next;
        }while(curr != *head_ref  && curr->data <= val);

        Node* node;
        node->data = val;
        node->next = curr;
        prev ->next = node;
    }
}*/
int main()
{

    int arr[] = {12, 56, 2, 11, 1, 90};
    int list_size, i;

    /* start with empty linked list */
    Node *start = NULL;


    /* Create linked list from the array arr[].
        Created linked list will be 1->2->11->12->56->90 */
    for (i = 0; i< 6; i++)
    {
        insertSorted1(&start, arr[i]);
    }

    printList(start);
	return 0;
}
