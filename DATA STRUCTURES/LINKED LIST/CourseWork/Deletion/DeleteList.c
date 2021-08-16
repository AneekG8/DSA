#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
void append(Node **head,int val)
{
	Node *last=*head;
	Node *new_node=(Node*)malloc(sizeof(Node));
	new_node->data=val;
	new_node->next=NULL;
	if(*head==NULL)
	{
		*head=new_node;
		return;
	}
	while(last->next!=NULL)
	{
		last=last->next;
	}
	last->next=new_node;
}
void DISP(Node *head)
{
 	if(head==NULL)
 	{
 		printf("LIST IS EMPTY\n\n");
 		return;
	}
	printf("LIST IS:-\n");
	 while(head!=NULL)
	 {
	 	printf("|%d|",head->data);
	 	head=head->next;
	 }
	 printf("\n\n");
}
void DEL(Node **head)
{
	Node *last;
	if(*head==NULL)
	{
		printf("LIST IS EMPTY\n\n");
		return;
	}
	while(*head!=NULL)
	{
	last=*head;
	*head=(*head)->next;
	free(last);	
	}
}
int main()
{
	Node *head=NULL;
	DEL(&head);
	append(&head,10);
	append(&head,15);
	DISP(head);
	DEL(&head);
	DISP(head);
	append(&head,23);
	append(&head,34);
	DISP(head);
	return 0;
}
