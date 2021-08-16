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
}
int del(Node **head,int pos)
{
	Node *prev=*head;
	if(*head==NULL)
	{
		printf("LIST IS EMPTY\n");
	}
	else if((*head)->next==NULL&&pos==0)
	{
		printf("DELETED %d\n",(*head)->data);
		*head=NULL;
	}
	else if((*head)->next!=NULL&&pos==0)
	{
		printf("DELETED %d\n",(*head)->data);
		*head=(*head)->next;
	}
	else
	{
		while(prev->next!=NULL&&pos>1)
		{
			prev=prev->next;
			pos--;
		}
		if(prev->next==NULL)
			printf("%d POSITION DOESNOT EXIST IN THE LIST\n",pos);
		else
		{
			printf("DELETED %d\n",prev->next->data);
			prev->next=prev->next->next;
		}
	}
}
int PEEK(Node *head)
{
	Node *last=head;
	if(last==NULL)
	{
		printf("QUEUE IS EMPTY\n");
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
int main()
{
	Node *head=NULL;
	del(&head,2);
	DISP(head);
	append(&head,34);
	DISP(head);
	del(&head,0);
	DISP(head);
	append(&head,34);
	DISP(head);
	append(&head,30);
	del(&head,9);
	DISP(head);
	append(&head,36);
	append(&head,39);
	DISP(head);
	del(&head,3);
	DISP(head);
	del(&head,0);
	DISP(head);
	del(&head,1);
	DISP(head);
	del(&head,0);
	DISP(head);
	return 0;
}
