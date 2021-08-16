#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
void PUSH(Node **head,int val)
{
	Node *new_node=(Node*)malloc(sizeof(Node));
	Node *last=*head;
	new_node->data=val;
	new_node->next=NULL;
	if(*head==NULL)
	{
		*head=new_node;
		return;
	}
	while(last->next!=NULL)
		last=last->next;
	last->next=new_node;
	return;	
}
int POP(Node **head)
{
	Node *prev;
	Node *last=*head;
	if(*head==NULL)
	{
		printf("STACK IS EMPTY\n");
		return;
	}
	if((*head)->next==NULL)
	{
		int x=(*head)->data;
		*head=NULL;
		return x;
	}
	while(last->next!=NULL)
	{
		prev=last;
		last=last->next;
	}
	prev->next=NULL;
	return last->data;
}
int PEEK(Node *head)
{
	Node *last=head;
	if(last==NULL)
	{
		printf("stack is empty\n");
		return;
	}
	while(last->next!=NULL)
	{
		last=last->next;
	}
	return last->data;
}
void DISP(Node *node)
{
	if(node==NULL)
	{
		printf("STACK IS EMPTY\n");
		return;
	}
	while(node!=NULL)
	{
		printf("|%d|",node->data);
		node=node->next;
	}
	printf("\n");
}
int main()
{
	Node *head=NULL;
	POP(&head);
	PUSH(&head,1);
	DISP(head);
	PUSH(&head,2);
	PUSH(&head,3);
	PUSH(&head,4);
	DISP(head);
	POP(&head);
	DISP(head);
	POP(&head);
	DISP(head);
	printf("peek is %d\n",PEEK(head));
	POP(&head);
	DISP(head);
	POP(&head);
	DISP(head);
	POP(&head);
	DISP(head);
	return 0;
}
