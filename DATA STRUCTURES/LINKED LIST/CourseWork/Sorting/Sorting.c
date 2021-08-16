#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
int isempty(Node *head)
{
	return head==NULL;
}
void append(Node **head,int val)
{
	Node *new_node=(Node*)malloc(sizeof(Node));
	Node *last=*head;
	new_node->data=val;
	new_node->next=NULL;
	if(isempty(*head))
	{
		*head=new_node;
		return;
	}
	while(last->next!=NULL)
		last=last->next;
	last->next=new_node;
	return;	
}void DISP(Node *node)
{
	if(node==NULL)
	{
		printf("\t\tEMPTY\n");
		return;
	}
	printf("\t\t");
	while(node!=NULL)
	{
		printf("|%d|",node->data);
		node=node->next;
	}
	printf("\n");
}
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
void sort(Node *head)
{
	Node *temp=head;
	while(temp)
	{
		Node *min=temp;
		Node *r=min->next;
		while(r)
		{
			if(min->data>r->data)
				min=r;
			r=r->next;	
		}
		swap(&(temp->data),&(min->data));
		temp=temp->next;
	}
}
int main()
{
	Node *head=NULL;
	append(&head,23);
	append(&head,99);
	append(&head,10);
	append(&head,23);
	append(&head,00);
	DISP(head);
	sort(head);
	DISP(head);
	return 0;
}
